#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
ll dp[10000001];
void pre()
{
    dp[1]=dp[2]=0;
    ll l=2;
    for(ll i=3; i<=1000001; i++)
    {
        dp[i]=(l*(l-1LL))/2LL;
        //cout<<dp[i]<<" ";
        dp[i]=(dp[i-1]%MOD+dp[i]%MOD)%MOD;
        if(dp[i]<0)dp[i]+=MOD;
        //cout<<dp[i]<<"\n";
        l++;
    }
}
int main()
{
    pre();
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        ll l,r;
        scanf("%lld %lld",&l,&r);
        if(l>r)swap(l,r);
        ll ans=dp[r]-dp[l-1];
        if(ans<0)ans+=MOD;
        printf("%lld\n",ans);
    }
}
