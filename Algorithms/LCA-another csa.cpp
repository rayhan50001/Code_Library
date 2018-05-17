//csa with sparse table
#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

const int Nmax = 1e5 + 5;
const int logNmax = 18;

int depth[Nmax], pos[Nmax], euler[2 * Nmax], rmq[logNmax][2 * Nmax], l[2 *Nmax], euler_count,dist[Nmax];
vector<pair<int,int> > v[Nmax];

void dfs(int x, int p)
{
    euler[++euler_count] = x;
    pos[x] = euler_count;
    if (p)
    {
        depth[x] = depth[p] + 1;
    }
    for (auto &it: v[x])
    {
        int weight=it.second;
        if (it.first != p)
        {
            dist[it.first]=dist[x]+weight;
            dfs(it.first, x);
            euler[++euler_count] = x;
        }
    }
}

int lca(int x, int y)
{
    if (pos[x] > pos[y])
    {
        swap(x, y);
    }
    int dif = pos[y] - pos[x] + 1;
    int log_dif = l[dif];

    int best = rmq[log_dif][pos[x]];
    if (depth[rmq[log_dif][pos[x] + dif - (1 << log_dif)]] < depth[best])
    {
        best = rmq[log_dif][pos[x] + dif - (1 << log_dif)];
    }

    return best;
}

int distance(int x, int y) {
    return dist[x] + dist[y] - 2 * dist[lca(x, y)];
}

void initLCA() {
    dfs(1, 0);

    for (int i = 2; i <= euler_count; ++i) {
        l[i] = l[i / 2] + 1;
    }

    for (int i = 1; i <= euler_count; ++i) {
        rmq[0][i] = euler[i];
    }

    for (int j = 1; (1 << j) <= euler_count; ++j)
    {
        for (int i = 1; i <= euler_count; ++i)
        {
            rmq[j][i] = rmq[j - 1][i];
            if (i + (1 << (j - 1)) <= euler_count)
            {
                if (depth[rmq[j - 1][i + (1 << (j - 1))]] < depth[rmq[j][i]])
                {
                    rmq[j][i] = rmq[j - 1][i + (1 << (j - 1))];
                }
            }
        }
    }
}
int kth(int lvl,int kth)
{
    int stp;
	for(stp = 1; 1<<stp <= l[lvl]; stp++); stp--;
    for(int i=stp; i>=0; i--)
    {
        if((l[lvl]-(1<<i))>=kth)
        {
            lvl=rmq[i][lvl];
        }
    }
    return lvl;
}
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
    int n, q;
    cin >> n;
    for(int i=1; i<=n; i++)v[i].clear();
    for (int i = 1; i < n; ++i)
    {
        int x, y, c;
        cin >> x >> y >> c;
        v[x].push_back({y,c});
        v[y].push_back({x,c});
    }
    initLCA();
    while(true)
    {
        string s;
        cin>>s;
        if(s=="DIST")
        {
            int u,v;
            cin>>u>>v;
            int ans=distance(u,v);
            cout<<ans<<endl;
        }
        else if(s=="KTH")
        {
            int u,v,k;
            cin>>u>>v>>k;
            int l_c_a=lca(u,v);
            int is_left=l[u]-l[l_c_a]+1;
            int ans=0;
            if(is_left>=k)
            {
                ans=kth(u,l[u]-k+1);
            }
            else
            {
               ans=kth(v,2*l[l_c_a]+k-l[u]-1);
            }
            cout<<ans<<endl;
        }
        else break;
    }
    }

    return 0;
}

