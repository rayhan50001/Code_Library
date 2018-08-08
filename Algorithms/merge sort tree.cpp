void build(int pos, int l, int r)
{
    tree[pos].clear();                              // Clears past values
    if(l == r)
    {
        tree[pos].push_back(v[l-1].first);
        return;
    }
    int mid = (l+r)>>1;
    build(pos<<1, l, mid);
    build(pos<<1|1, mid+1, r);
    merge(tree[pos<<1].begin(), tree[pos<<1].end(), tree[pos<<1|1].begin(), tree[pos<<1|1].end(), back_inserter(tree[pos]));
}

int query(int pos, int l, int r, int L, int R, int k)
{
    if(r < L || R < l) return 0;
    if(L <= l && r <= R)//query part
    {
        auto it = upper_bound(tree[pos].begin(), tree[pos].end(), k);
        it-=1;
        if(L-R==0 && *it==k)return 0;
        else return *(it);
    }
    int mid = (l+r)>>1;
    return max(query(pos<<1, l, mid, L, R, k),query(pos<<1|1, mid+1, r, L, R, k));
}
void insertST(int n, int l, int rl, int q, int k)
{
    if (k >= l && k <= rl)
    {
        tree[n].push_back(q);
        if (l != rl)
        {
            insertST((n<<1), l, ((l+rl)>>1), q, k);
            insertST((n<<1)|1, ((l+rl)>>1)+1, rl, q, k);
            //merge(tree[n<<1].begin(), tree[n<<1].end(), tree[n<<1|1].begin(), tree[n<<1|1].end(), back_inserter(tree[n]));
        }
    }
}
void removeST(int n, int l, int rl, int q)
{
    if (q >= l && q <= rl)
    {
        tree[n].pop_back();
        if (l != rl)
        {
            removeST((n<<1), l, ((l+rl)>>1), q);
            removeST((n<<1)|1, ((l+rl)>>1)+1, rl, q);
            //merge(tree[n<<1].begin(), tree[n<<1].end(), tree[n<<1|1].begin(), tree[n<<1|1].end(), back_inserter(tree[n]));
        }
    }
}
