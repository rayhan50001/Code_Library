#include<bits/stdc++.h>
using namespace std;
int dist[101][101];
int main()
{
    //freopen("out.txt","w",stdout);
    int tt,kk=1;
    cin>>tt;
    printf("SHIPPING ROUTES OUTPUT\n");
    while(tt--)
    {
        printf("\nDATA SET  %d\n\n",kk++);//2 space
        int n,m,q;
        cin>>n>>m>>q;
        map<string,int>mp;
        for(int i=1; i<=n; i++)
        {
            string s;
            cin>>s;
            mp[s]=i;
        }
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                dist[i][j]=10000;
            }
            dist[i][i]=0;
        }
        for(int i=0; i<m; i++)
        {
            string s1,s2;
            cin>>s1>>s2;
            //cout<<dist[mp[s1]][mp[s2]]<<endl;
            dist[mp[s1]][mp[s2]]=1;
            dist[mp[s2]][mp[s1]]=1;
        }
        //system("pause");
        for(int k=1; k<=n; k++)
        {
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=n; j++)
                {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        while(q--)
        {
            int sz;
            string s1,s2;
            cin>>sz>>s1>>s2;
            int st=mp[s1];
            int ed=mp[s2];
            if(dist[st][ed]==10000)printf("NO SHIPMENT POSSIBLE\n");
            else printf("$%d\n",sz*dist[st][ed]*100);
        }
    }
    printf("\nEND OF OUTPUT\n");
}
