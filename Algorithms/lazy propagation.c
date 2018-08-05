ll tree[6*100009];
ll lazy[6*100009];
void build(ll node, ll a, ll b)
{
    if(a>b) return;
    if (a==b)
    {
        tree[node]=0;
        return;
    }
    build(node*2, a, (a+b)/2);
    build(node*2+1,(a+b)/2+1,b);
    tree[node]=tree[node*2]+tree[node*2+1];
}
ll query(ll node, ll a, ll b, ll i, ll j)
{
    if(a>b||a>j||b<i) return 0;
    if (lazy[node] !=-1)
    {
        tree[node]=lazy[node]*(b-a+1);
        if (a!=b)
        {
            lazy[node*2]=lazy[node];
            lazy[node*2+1]=lazy[node];
        }
        lazy[node]=-1;
    }

    if (a>=i && b<=j) return tree[node];

    ll q1=query(node*2, a, (a+b)/2, i, j);
    ll q2=query(node*2+1, (a+b)/2+1, b, i, j);

    return q1+q2;
}
void update(ll node, ll a, ll b, ll i, ll j, ll inc)
{
    if(a>b) return;
    if (lazy[node]!=-1)
    {
        tree[node]=lazy[node]*(b-a+1);
        if (a!=b)
        {
            lazy[node*2]=lazy[node];
            lazy[node*2+1]=lazy[node];
        }
        lazy[node]=-1;
    }
    if(a>b||a>j||b<i) return;

    if (a>=i && b<=j)
    {
        tree[node]=inc*(b-a+1);
        if (a!=b)
        {
            lazy[node*2]=inc;
            lazy[node*2+1]=inc;
        }
        return;
    }

    update(node*2, a, (a+b)/2, i, j, inc);
    update(node*2+1, (a+b)/2+1, b,i, j, inc);
    tree[node] = tree[node*2] + tree[node*2+1];
}
