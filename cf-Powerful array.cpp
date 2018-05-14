#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct MO{
    int l, r, id, block;
    bool operator < ( const MO& p) const {
		return block == p.block ? r < p.r : block < p.block;
	}
}Q[1000001];
ll cnt[1000001], arr[1000001], ans[1000001], sum=0;
void add(ll x)
{
    sum+=(cnt[x]+cnt[x]+1)*x;
    cnt[x]++;
}
void del(ll x)
{
    sum+=(cnt[x]+cnt[x]-1)*x;
    cnt[x]--;
}
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=0; i<n; i++)
    {
        scanf("%lld",&arr[i]);
    }
    int total_block = sqrt(n)+1;
    for(int i=0; i<q; i++)
    {
        scanf("%d %d",&Q[i].l,&Q[i].r);
        Q[i].l--;
        Q[i].r--;
        Q[i].id=i;
        Q[i].block = Q[i].l / total_block;
    }
    sort(Q,Q+q);
    int l=0,r=-1;
    for(int i=0; i<q; i++)
    {
        while(l > Q[i].l)add(arr[--l]);
        while(r < Q[i].r)add(arr[++r]);
        while(l < Q[i].l)del(arr[l++]);
        while(r > Q[i].r)del(arr[r--]);
        ans[Q[i].id]=sum;
    }
    for(int i=0; i<q; i++)
    {
        printf("%lld\n",ans[i]);
    }
}
