//SCC(strongly connected component)
#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100001];
vector<int> rgraph[100001];
int vis[100001];
int comp[100001];
map<string, int>mp;
vector<string>name;
vector<int> topsort;
void reset()
{
    for(int i=0; i<50; i++)
    {
        graph[i].clear();
        rgraph[i].clear();
    }
    memset(vis,0,sizeof vis);
    mp.clear();
    name.clear();
    topsort.clear();
    memset(comp,0,sizeof comp);
}
void dfs1(int u){
    vis[u] =1;

    for(int i=0;i<graph[u].size(); i++)
    {
        int v = graph[u][i];
        if (!vis[v])
            dfs1(v);
    }

    topsort.push_back(u);
}
void dfs2(int u, int cmp){
    vis[u] = 1;
    comp[u] = cmp;

    for (int i=0;i<rgraph[u].size();i++){
        int v = rgraph[u][i];

        if (vis[v]==0)
            dfs2(v, cmp);
    }
}
int main()
{
    int n,m,kk=1;
    int newline=false;
    while(cin>>n>>m && n && m)
    {
        if(newline)cout<<endl;
        newline=false;
        reset();
        int len=0;
        for(int i=0; i<m; i++)
        {
              string s1,s2;
              cin>>s1>>s2;
              if(!mp[s1])
              {
                  mp[s1]=++len;
                  name.push_back(s1);
              }
              if(!mp[s2])
              {
                  mp[s2]=++len;
                  name.push_back(s2);
              }
              graph[mp[s1]].push_back(mp[s2]);
              rgraph[mp[s2]].push_back(mp[s1]);
        }
        for(int i=1;i<=len;i++)
            if (vis[i] == 0)
                dfs1(i);

        reverse(topsort.begin(), topsort.end());
        memset(vis,0, sizeof(vis));

        int cmp = 0;
        for (int i=0;i<topsort.size();i++){
            if (vis[topsort[i]] == 0 ){
                ++cmp;
                dfs2(topsort[i],cmp);
            }
        }
        printf ("Calling circles for data set %d:\n", kk++);
        for(int i=1; i<=cmp; i++)
        {
            bool space=false;
            for(int j=0; j<n; j++)
            {
                if(comp[j+1]==i)
                {
                    if(space)cout<<", ";
                    space=true;
                    cout<<name[j];
                }
            }
            cout<<endl;
        }
    }
}
