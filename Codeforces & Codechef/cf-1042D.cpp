#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll cum[300001];
ll arr[300001];
vector<ll>tree[1000001];
void build(ll node,ll l,ll r)
{
    if(l==r)
    {
        tree[node].push_back(cum[l]);
        return;
    }
    ll mid=(l+r)/2;
    ll lft=2*node;
    ll rgt=lft+1;
    build(lft,l,mid);
    build(rgt,mid+1,r);
    merge(tree[lft].begin(), tree[lft].end(), tree[rgt].begin(), tree[rgt].end(), back_inserter(tree[node]));
}
ll query(ll node,ll l,ll r,ll s,ll e,ll t)
{
    if(r < s || e < l) return 0;
     if(s <= l && r <= e)
     {
         return lower_bound(tree[node].begin(),tree[node].end(),t)-tree[node].begin();
     }
    ll mid=(l+r)/2;
    ll lft=2*node;
    ll rgt=lft+1;
    ll left=query(lft,l,mid,s,e,t);
    ll right=query(rgt,mid+1,r,s,e,t);
    return left+right;
}
int main()
{
    ll n,t;
    scanf("%lld %lld",&n,&t);
    cum[0]=0;
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&arr[i]);
        cum[i]=cum[i-1]+arr[i];
    }
    build(1,1,n);
    ll ans=0;
    for(ll i=1; i<=n; i++)
    {
        ans+=query(1,1,n,i,n,cum[i-1]+t);
    }
    printf("%lld\n",ans);
}
