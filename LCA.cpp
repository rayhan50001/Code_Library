/*Take an array named E[], which stores the order of dfs traversal i.e. the order in which the nodes are covered during the dfs traversal.
The tree given above has dfs traversal in the order: 1-2-4-2-5-2-1-3.

Take another array L[], in which L[i] is the level of node E[i].

And the array H[], which stores the index of first occurrence of ith node in the array E[].

So, for the above tree,
E[] = {1, 2, 4, 2, 5, 2, 1, 3}
L[] = {1, 2, 3, 2, 3, 2, 1, 2}
H[] = {0, 1, 7, 2, 4}
Note that the arrays E and L are with zero-based indexing but the array H has one-based indexing.

Now, to find the LCA(4, 3), first use the array H and find the indices at which 4 and 3 are found in E i.e. H[4] and H[3]. So, the indices comes out to be 2 and 7. Now, look at the subarray L[2 : 7], and find the minimum in this subarray which is 1 (at the 6th index), and the corresponding element in the array E i.e. E[6] is the LCA(4, 3).

To understand why this works, take LCA(4, 3) again. The path by which one can reach node 3 from node 4 is the subarray E[2 : 7] . And, if there is a node with lowest level in this path, then it can simply claimed to be the LCA(4, 3).

Now, the problem is to find the minimum in the subarray E[H[u]….H[v]] (assuming that H[u] >= H[v]). And, that could be done using segment tree or sparse table. Below is the code using segment tree.
*/
#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>

#define sz(x) x.size()
#define pb push_back
#define left 2 * i + 1
#define right 2 * i + 2
using namespace std;

const int maxn = 1001;

// the graph
vector<vector<int>> g(maxn);
int level[maxn];
vector<int> e;
vector<int> l;
int h[maxn];
int st[5 * maxn];
void add_edge(int u, int v)
{
    g[u].pb(v);
    g[v].pb(u);
}

// assigning level to nodes
void leveling(int src)
{
    for (int i = 0; i < sz(g[src]); i++)
    {
        int des = g[src][i];
        if (!level[des])
        {
            level[des] = level[src] + 1;
            leveling(des);
        }
    }
}

bool visited[maxn];

// storing the dfs traversal
// in the array e
void dfs(int src)
{
    e.pb(src);
    visited[src] = 1;
    for (int i = 0; i < sz(g[src]); i++)
    {
        int des = g[src][i];
        if (!visited[des])
        {
            dfs(des);
            e.pb(src);
        }
    }
}

// making the array l
void setting_l(int n)
{
    for (int i = 0; i < sz(e); i++)
        l.pb(level[e[i]]);
}

// making the array h
void setting_h(int n)
{
    for (int i = 0; i <= n; i++)
        h[i] = -1;
    for (int i = 0; i < sz(e); i++)
    {
        // if is already stored
        if (h[e[i]] == -1)
            h[e[i]] = i;
    }
}

// Range minimum query to return the index
// of minimum in the subarray L[qs:qe]
int RMQ(int ss, int se, int qs, int qe, int i)
{
    if (ss > se)
        return -1;

    // out of range
    if (se < qs || qe < ss)
        return -1;

    // in the range
    if (qs <= ss && se <= qe)
        return st[i];

    int mid = (ss + se) >> 1;
    int st = RMQ(ss, mid, qs, qe, left);
    int en = RMQ(mid + 1, se, qs, qe, right);

    if (st != -1 && en != -1)
    {
        if (l[st] < l[en])
            return st;
        return en;
    }
    else if (st != -1)
        return st;
    else if (en != -1)
        return en;
}

// constructs the segment tree
void SegmentTreeConstruction(int ss, int se, int i)
{
    if (ss > se)
        return;
    if (ss == se) // leaf
    {
        st[i] = ss;
        return;
    }
    int mid = (ss + se) >> 1;

    SegmentTreeConstruction(ss, mid, left);
    SegmentTreeConstruction(mid + 1, se, right);

    if (l[st[left]] < l[st[right]])
        st[i] = st[left];
    else
        st[i] = st[right];
}

// Funtion to get LCA
int LCA(int x, int y)
{
    if (h[x] > h[y])
        swap(x, y);
    return e[RMQ(0, sz(l) - 1, h[x], h[y], 0)];
}

// Driver code
int main()
{
    ios::sync_with_stdio(0);
    int tt,kk=1;
    scanf("%d",&tt);
    while(tt--)
    {
        memset(level,0,sizeof level);
        memset(visited,false,sizeof visited);
        memset(h,0,sizeof h);
        memset(st,0,sizeof st);
        e.clear();
        l.clear();
        g.clear();
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
        {
            int u=i;
            int x;
            scanf("%d",&x);
            for(int j=0; j<x; j++)
            {
                int v;
                scanf("%d",&v);
                add_edge(u,v);
            }
        }
        level[1] = 1;
        leveling(1);
        dfs(1);
        setting_l(n);
        setting_h(n);
        SegmentTreeConstruction(0, sz(l) - 1, 0);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",kk++);
        while(q--)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            printf("%d\n",LCA(u,v));
        }
    }
    return 0;
}
