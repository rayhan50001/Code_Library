#include<bits/stdc++.h>
using namespace std;
#define MAX 100009
int ans[MAX], arr[MAX], sum=0;
unordered_map<int,int>cnt;
struct MO{
int l, r, id, block;
    bool operator < (const MO& p) const{
    if(block==p.block)return r<p.r;
    return block<p.block;
    }
}query[MAX];
void add(int x)
{
    x=arr[x];
    cnt[x]++;
    if(cnt[x]==x)sum++;
    if(cnt[x]-1==x)sum--;
}
void del(int x)
{
    x=arr[x];
    cnt[x]--;
    if(cnt[x]==x)sum++;
    if(cnt[x]+1==x)sum--;
}
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int total = sqrt(n)+1;
    for(int i=0; i<q; i++)
    {
        scanf("%d %d",&query[i].l,&query[i].r);
        query[i].l--;
        query[i].r--;
        query[i].id=i;
        query[i].block = query[i].l / total;
    }
    sort(query,query+q);
    int l=0,r=-1;

    for(int i=0; i<q; i++)
    {
        while(l>query[i].l)add(--l);
        while(r<query[i].r)add(++r);
        while(l<query[i].l)del(l++);
        while(r>query[i].r)del(r--);

        ans[query[i].id]=sum;
    }
    for(int i=0; i<q; i++)
    {
        printf("%d\n", ans[i]);
    }
}
