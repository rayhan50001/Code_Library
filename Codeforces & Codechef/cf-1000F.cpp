#include<bits/stdc++.h>
using namespace std;
const int maxn=500010;
struct query
{
  int l, r, id;
} q[maxn];

const int block=715;

bool cmp(query &a,query &b)
{
	if(a.l/block !=b.l/block)   return a.l < b.l;
	if((a.l/block)&1)           return a.r < b.r;
	return a.r > b.r;
}
int once  = 0, ans[maxn], cnt[maxn], n,freq[maxn], arr[maxn], blocks[block];
void add(int x)
{
    int xx=arr[x];
    ++cnt[xx];
    if(cnt[xx]==1)
    {
        ++once;
 //       ++freq[xx];
        ++blocks[xx/block];
    }
    else if(cnt[xx]==2)
    {
        --once;
 //       --freq[xx];
        --blocks[xx/block];
    }
}
void remove(int x)
{
    int xx=arr[x];
    --cnt[xx];
    if(cnt[xx]==0)
    {
         --once;
 //       --freq[xx];
         --blocks[xx/block];
    }
    else if(cnt[xx]==1)
    {
         ++once;
 //        ++freq[xx];
         ++blocks[xx/block];
    }
}
int res(int l,int r)
{
    if(!once)return 0;
    for(int i=0; i<block; ++i)
    {
        if(blocks[i])
        {
            int lim=i*block+block;
            for(int j=i*block; j<=lim; ++j)
            {
                if(cnt[j]==1)
                {
                    return j;
                }
            }
        }
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int qq;
    scanf("%d",&qq);
    for(int i=0; i<qq; i++)
    {
        int l,r;
        scanf("%d %d",&q[i].l,&q[i].r);
        --q[i].l;
        --q[i].r;
        q[i].id=i;
    }

    sort(q,q+qq,cmp);

    int l=0, r=-1;
    for(int i=0; i<qq; i++)
    {
        while(l > q[i].l) add(--l);
        while(r < q[i].r) add(++r);
        while(l < q[i].l) remove(l++);
        while(r > q[i].r) remove(r--);
        //cout<<q[i].l<<" "<<q[i].r<<" "<<once<<endl;
        ans[q[i].id]=res(q[i].l,q[i].r);
    }
    for(int i=0; i<qq; i++)
    {
       printf("%d\n",ans[i]);
    }
    return 0;
}
