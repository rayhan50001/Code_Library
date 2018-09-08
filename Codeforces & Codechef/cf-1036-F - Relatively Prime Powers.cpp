By rayhan50001, contest: Educational Codeforces Round 50 (Rated for Div. 2), problem: (F) Relatively Prime Powers, Accepted, #
 #include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000000000000000
vector<ll>v;
set<ll>s;
void pre()
{
    for(ll i=2; i<=1000000; i++)
    {
        ll j=i*i;
        while(j<=MAX/i)
        {
            j=j*i;
            ll sq=sqrtl(j);
            if((sq*sq)!=j)s.insert(j);
        }
    }
    for(auto it: s)v.push_back(it);
}
int main()
{
        pre();
        //for(int i=0; i<100; i++)cout<<v[i]<<" ";
        int tt;
        scanf("%d",&tt);
        while(tt--)
        {
            ll n;
            scanf("%lld",&n);
            ll perfect_square=sqrtl(n);
            //cout<<perfect_square<<endl;
            ll l=lower_bound(v.begin(),v.end(),1)-v.begin();
            ll h=upper_bound(v.begin(),v.end(),n)-v.begin();
            ll total=(h-l)+perfect_square;
            //cout<<h-l<<endl;
            ll ans=n-total;
            printf("%lld\n",ans);
        }
}
