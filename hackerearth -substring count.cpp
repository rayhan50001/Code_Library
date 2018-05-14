#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v[100001];
ll power[100001];
#define base 37
#define MOD 1000000007
void pw()
{
    power[0]=1;
    for(int i=1; i<=10000; i++)power[i]=(power[i-1]*base)%MOD;
}
ll haSH(string s)
{
    ll sum=0;
    for (int k = 0; k <s.size(); k++)
        sum=(sum+(power[k+1]*(s[k]-'a'+1))%MOD)%MOD;
    return sum;
}
int main()
{
    pw();
    int n;
    scanf("%d",&n);
    for(int p=1; p<=n; p++)
    {
        string s;
        cin>>s;
        int n=s.size();
        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                ll HASH=0;
                string sss;
                for (int k = i; k <= j; k++){
                    HASH=(HASH+(power[k+1]*(s[k]-'a'+1))%MOD)%MOD;
                    sss+=s[k];
                }
                cout<<sss<<" "<<HASH<<endl;
                v[HASH].push_back(p);
            }
        }
    }
    int q;
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        string s1;
        cin>>s1;
        ll ss=haSH(s1);
        int low=lower_bound(v[ss].begin(),v[ss].end(),l)-v[ss].begin();
        int high=upper_bound(v[ss].begin(),v[ss].end(),r)-v[ss].begin();
        printf("%d\n",high-low);
    }

}
