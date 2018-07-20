#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100001];
int vis[100001];
int par[100001];
int main()
{
    int tt,kk=1;
    cin>>tt;
    while(tt--)
    {
        if(kk++>1)cout<<"\n";
        memset(vis,0,sizeof vis);
        memset(par,0,sizeof par);
        int n,m;
        cin>>n>>m;
        map<string,int>no;
        map<int,string>name;
        int total=0;
        for(int i=0; i<n; i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            if(!no[s1])
            {
                no[s1]=++total;
                name[total]=s1;
            }
            if(!no[s2])
            {
                no[s2]=++total;
                name[total]=s2;
            }
            graph[no[s1]].push_back(no[s2]);
            graph[no[s2]].push_back(no[s1]);
        }
        while(m--)
        {
            string s1,s2;
            cin>>s1>>s2;
            int st=no[s1];
            int ed=no[s2];
            memset(vis,0,sizeof vis);
            memset(par,0,sizeof par);
            queue<int>q;
            q.push(st);
            vis[st]=1;
            while(!q.empty())
            {
                int next=q.front();
                q.pop();
                if(next==ed)break;
                for(int i=0; i<graph[next].size(); i++)
                {
                    int v=graph[next][i];
                    if(!vis[v])
                    {
                            par[v]=next;
                            vis[v]=1;
                            q.push(v);
                    }
                }
            }
            int j=ed;
            string ans;
            while(j!=st)
            {
                ans+=name[j][0];
                j=par[j];
                //cout<<j<<" "<<par[j]<<endl;
            }
            ans+=name[st][0];
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
        }
        for(int i=0; i<=total; i++)graph[i].clear();
    }
}
