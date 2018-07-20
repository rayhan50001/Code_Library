#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll power(ll x, unsigned int y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res*x;
        y = y>>1;
        x = x*x;
    }
    return res;
}
vector<ll>pow23;
void pre()
{
    ll largest=power(2LL,31);
    for(int i=0; i<=32; i++)
    {
        for(int j=0; j<=28; j++)
        {
            ll cal=power(2LL,i)*power(3LL,j);
            if(cal<=largest)pow23.push_back(cal);
            else break;
        }
    }
    sort(pow23.begin(),pow23.end());
}
int main()
{
    pre();
    int n;
    while(cin>>n && n)
    {
        int low=lower_bound(pow23.begin(),pow23.end(),n)-pow23.begin();
        if(pow23[low]<n)low++;
        printf("%lld\n",pow23[low]);
    }
}
