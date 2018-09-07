#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>arr;
void pre()
{
    for(ll i=1; i<=100000; i++)
    {
        ll val=i*i*i*i;
        ll sq=sqrtl(val);
        ll cub=cbrtl(val);
        if(val>1e18)break;
        if(sq*sq==val && cub*cub*cub==val)arr.push_back(val);
    }
    sort(arr.begin(),arr.end());
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
        int low=lower_bound(arr.begin(),arr.end(),l)-arr.begin();
        int high=upper_bound(arr.begin(),arr.end(),r)-arr.begin();
        printf("%d\n",high-low);
    }
}
