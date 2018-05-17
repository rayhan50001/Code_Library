#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>    // rb_Tree_tag
#include <ext/pb_ds/Tree_policy.hpp>        // Tree_order_statistics_node_update

#define MAX 10000


using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct node {
    ll val;
    int idx;

    void Merge(node lft, node rht) {
        if(lft.val > rht.val) {
            val = lft.val;
            idx = lft.idx;
        }
        else if(rht.val > lft.val) {
            val = rht.val;
            idx = rht.idx;
        }
        else {
            val = lft.val;
            idx = min(lft.idx, rht.idx);
        }
    }
};

ll val[MAX];
node Tree[5*MAX];
ll vis[100009];
void init(int pos, int l, int r) {
    if(l == r) {
        Tree[pos].val = val[l];
        Tree[pos].idx = l;
        return;
    }

    int mid = (l+r)>>1;

    init(pos<<1, l, mid);
    init(pos<<1|1, mid+1, r);

    Tree[pos].Merge(Tree[pos<<1], Tree[pos<<1|1]);
}


node query(int pos, int l, int r, int L, int R) {
    if(r < L || R < l) {
        node tmp;
        tmp.val = -1, tmp.idx = -1;
        return tmp;
    }

    if(L <= l && r <= R)
        return Tree[pos];

    int mid = (l+r)>>1;

    node x = query(pos<<1, l, mid, L, R);
    node y = query(pos<<1|1, mid+1, r, L, R);

    node mrg;
    mrg.Merge(x, y);
    return mrg;
}

void update(int pos, int l, int r, int idx) {
    if(l == r) {
        Tree[pos].val = -1;
        return;
    }

    int mid = (l+r)>>1;

    if(idx <= mid)
        update(pos<<1, l, mid, idx);
    else
        update(pos<<1|1, mid+1, r, idx);
    Tree[pos].Merge(Tree[pos<<1], Tree[pos<<1|1]);
}



int main() {
    int n, k;
    ordered_set<int>Set;

    scanf("%d%d", &n, &k);

    // Inserting index
    for(int i = 1; i <=n; ++i)
        Set.insert(i);

    for(int i = 1; i <= n; ++i)
        scanf("%lld", &val[i]);

    init(1, 1, n);
    while(k > 0)
    {
        int len=Set.size();
        int selectpos=*Set.find_by_order(min(k,len-1));
        //cout<<selectpos<<" ";
        node mx = query(1, 1, n, 1, selectpos);
        cout<< mx.val << " ";
        vis[mx.idx]=1;
        update(1, 1, n, mx.idx);
        int actualpos=Set.order_of_key(mx.idx);
        Set.erase(Set.find_by_order(actualpos));
        k-=actualpos;
        //cout<<k<<endl;
////        int setpos=actualpos+(Set.size()-kk)-1;
////        k=setpos;
////        cout<<actualpos<<" "<<k<<" "<<setpos<<endl;
//        for(auto x : Set)
//        cout << x << " ";
//        cout<<endl;
//        system("pause");
    }

    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)cout<<val[i]<<" ";
    }
    cout<<endl;
    return 0;
}
