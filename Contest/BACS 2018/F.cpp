#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100001
vector<int>graph[100001];
int level[100001];
int vis[100001];
int arr[100001];
void dfs(int u,int lebel)
{
    level[u]=lebel;
    vis[u]=1;
    for(int i=0; i<graph[u].size(); i++)
    {
        if(!vis[graph[u][i]])
        {
            dfs(graph[u][i],lebel+1);
        }
    }
}
void check(int u)
{
    vis[u]=1;
    for(int i=0; i<graph[u].size(); i++)
    {
        if(!vis[graph[u][i]])
        {
            check(graph[u][i]);
        }
    }
}
int main()
{
        int tt;
        cin>>tt;
        while(tt--)
        {
            memset(vis,0,sizeof vis);
            int n;
            cin>>n;
            for(int i=1; i<=n; i++)
                cin>>arr[i];
            for(int i=2; i<=n; i++)
            {
                int x;
                cin>>x;
                graph[x].push_back(i);
            }
            dfs(1,0);
            int mx=0;
            for(int i=1; i<=n; i++)
            {
                mx=max(mx,level[i]);
            }
            map<int,int>lebel;
            for(int i=2; i<=n; i++)
            {
                memset(vis,0,sizeof vis);
                lebel.clear();
                check(i);
                int mx=0;
                //cout<<i<<" ==>\n ";
                for(int j=1; j<=n; j++)
                {
                    if(!vis[j])
                    {
                        if(j>1 && level[j]==0)continue;
                        //cout<<j<<" : "<<level[j]<<" "<<arr[j]<<"\n";
                        lebel[level[j]]+=arr[j];
                        mx=max(mx,lebel[level[j]]);
                        //system("pause");
                    }
                }
                cout<<mx<<endl;
            }
            for(int i=0; i<=n; i++)graph[i].clear();
            //system("pause");
        }
}
