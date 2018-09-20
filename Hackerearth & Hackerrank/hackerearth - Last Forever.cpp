#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 3e5 + 1, sigma = 26;
int len[maxn], link[maxn], to[maxn][sigma];
int slink[maxn], diff[maxn], series_ans[maxn];
int sz, last, n;
char s[maxn];
int ans[maxn];
void init()
{
    s[n++] = -1;
    link[0] = 1;
    len[1] = -1;
    sz = 2;
}

int get_link(int v)
{
    while(s[n - len[v] - 2] != s[n - 1]) v = link[v];
    return v;
}

void add_letter(char c)
{
    s[n++] = c -= 'a';
    last = get_link(last);
    if(!to[last][c])
    {
        len[sz] = len[last] + 2;
        link[sz] = to[get_link(link[last])][c];
        diff[sz] = len[sz] - len[link[sz]];
        if(diff[sz] == diff[link[sz]])
            slink[sz] = slink[link[sz]];
        else
            slink[sz] = link[sz];
        to[last][c] = sz++;
    }
    last = to[last][c];
}
vector<ll>TREE[1000001];
void build(ll node,ll l,ll r)
{
    if(l==r)
    {
        TREE[node].push_back(0);
        return;
    }
    ll mid=(l+r)/2;
    ll lft=2*node;
    ll rgt=lft+1;
    build(lft,l,mid);
    build(rgt,mid+1,r);
    merge(TREE[lft].begin(), TREE[lft].end(), TREE[rgt].begin(), TREE[rgt].end(), back_inserter(TREE[node]));
}
ll query(ll node,ll l,ll r,ll s,ll e,ll t)
{
    if(r < s || e < l) return 0;
     if(s <= l && r <= e)
     {
         return lower_bound(TREE[node].begin(),TREE[node].end(),t)-TREE[node].begin();
     }
    ll mid=(l+r)/2;
    ll lft=2*node;
    ll rgt=lft+1;
    ll left=query(lft,l,mid,s,e,t);
    ll right=query(rgt,mid+1,r,s,e,t);
    return left+right;
}
void insertST(int idx,int l,int r,int val,int pos)
{
   if(l==pos && r==pos)
    {
        TREE[idx][0]=val;
        return;
    }
    int lft=2*idx;
    int rgt=2*idx+1;
    int mid=(l+r)/2;
    if(pos<=mid)
    {
        insertST(lft,l,mid,val,pos);
    }
    else
    {
        insertST(rgt,mid+1,r,val,pos);
    }
    //merge(TREE[lft].begin(), TREE[lft].end(), TREE[rgt].begin(), TREE[rgt].end(), back_inserter(TREE[idx]));
}
bool cmp(tuple<int,int,int>p1,tuple<int,int,int>p2)
{
    return get<0>(p1)>get<0>(p2);
}
int main() {
    //assert(freopen("input.txt", "r", stdin));
    //assert(freopen("output.txt", "w", stdout));
    scanf("%s",s);
    int q;
    scanf("%d",&q);
    init();
    vector<tuple<int,int,int> >v;
    for(int i=0; i<q; i++)
    {
         int L,length;
         scanf("%d %d",&L,&length);
         v.push_back(make_tuple(L,length,i));
    }
    sort(v.begin(),v.end(),cmp);

    int idx=get<0>(v[0]);

    int n=strlen(s);
    build(1,1,n);
    for(int i=n-1; i>idx; i--)
    {
        cout<<i<<" ";
        add_letter(s[i]);
        insertST(1,1,n,len[last],i+1);
    }
    cout<<endl;
    int last=-1;
    for(int j=0; j<v.size(); j++)
    {
        int L=get<0>(v[j]);
        int length=get<1>(v[j]);
        if(last==-1)
        {
            //cout<<L<<" ";
            add_letter(s[L]);
            insertST(1,1,n,len[last],j+1);
            last=L;
        }
        else
        {
            for(int i=last-1; i>=L; i--)
            {
                //cout<<i<<" ";
                add_letter(s[i]);
                insertST(1,1,n,len[last],j+1);
            }
        }
        L++;
        int aa=query(1,1,n,L,n,length);
        int res=(n-L+1)-aa;
        cout<<aa<<" "<<res<<endl;
        ans[get<2>(v[j])]=res;
    }
    cout<<endl;
    for(int i=0; i<v.size(); i++)cout<<ans[i]<<endl;
    return 0;
}
