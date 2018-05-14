#define ONLINE_JUDGE 1
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sf(n) scanf("%lld",&n)
ll max(ll a,ll b)
{
    if(a>b)return a;
    else return b;
}
ll min(ll a,ll b)
{
    if(a>b)return b;
    else return a;
}
ll arr[100];
int main()
{
    ll tt;
    scanf("%lld",&tt);
    while(tt--)
    {
        ll n;
        sf(n);
        for(ll i=0; i<n; i++)
        {
            sf(arr[i]);
        }
        long long mx1=-1e9,mx2=-1e9;
        ll mn1=1e18,mn2=1e18;
        ll len=0,len1=0;
        for(ll i=0; i<(1<<n); i++)
        {
            long long sum=1,sum2=1;
            ll last_pos=-1;
            ll first_pos=-1;
            ll sum1=1;
            for(ll j=0; j<n; j++)
            {
                if((i&(1<<j))==1<<j)
                {
                    sum=sum*arr[j];
                    last_pos=j+1;
                }
                else
                {
                    sum1=sum1*arr[j];
                    if(first_pos==-1)first_pos=j+1;
                }
            }
            cout<<last_pos<<" "<<first_pos<<endl;
            ll sq=sqrt(sum);
            ll sq1=sqrt(sum1);
            if(sq*sq==sum && last_pos!=-1 && first_pos!=-1 && last_pos>first_pos)
            {
                len++;
                mx1=max(mx1,sum);
                mn1=min(mn1,sum);
            }
            if(sq1*sq1==sum1 && last_pos!=-1 && first_pos!=-1 && last_pos>first_pos)
            {
                len1++;
                mx2=max(mx2,sum1);
                mn2=min(mn2,sum1);
            }
        }
        if(len && len1)
        {
           ll ans=max(abs(mn1-mx2),abs(mx1-mn2));
            printf("%lld\n",ans);
        }
        else
        {
            printf("-1\n");
        }

    }
}

