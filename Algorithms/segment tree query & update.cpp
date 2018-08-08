ll tree[4*MAX];
void build(int idx,int l,int r)
{
    if(l==r)
    {
        tree[idx]=v[l].first;
        return;
    }
    int lft=2*idx;
    int rgt=2*idx+1;
    int mid=(l+r)/2;
    build(lft,l,mid);
    build(rgt,mid+1,r);
    //tree[idx]=min(tree[lft],tree[rgt]);
    tree[idx]=max(tree[lft],tree[rgt]);
}
void update(int idx,int l,int r,int pos,int val)
{
    if(l==pos && r==pos)
    {
        tree[idx]=val;
        return;
    }
    int lft=2*idx;
    int rgt=2*idx+1;
    int mid=(l+r)/2;
    if(pos<=mid)
    {
        update(lft,l,mid,pos,val);
    }
    else
    {
        update(rgt,mid+1,r,pos,val);
    }
    //tree[idx]=min(tree[lft],tree[rgt]);
    tree[idx]=max(tree[lft],tree[rgt]);
}
int Query(int idx,int l,int r,int s,int e)
{
    if(l==s && r==e)
    {
        return tree[idx];
    }
    int lft=2*idx;
    int rgt=2*idx+1;
    int mid=(l+r)/2;
    if(e<=mid)
    {
        Query(lft,l,mid,s,e);
    }
    else if(s>mid)
    {
        Query(rgt,mid+1,r,s,e);
    }
    else
    {
        int q1=Query(lft,l,mid,s,mid);
        int q2=Query(rgt,mid+1,r,mid+1,e);
        //return min(q1,q2);
        return max(q1,q2);
    }
}
