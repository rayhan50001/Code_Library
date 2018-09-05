//Dijkstra's ( Shortest Path )
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int grid[1001][1001];
struct edge{
int r,c,cost;
    bool operator > (const edge &p)const{
    return cost>p.cost;
    }
};
bool isvalid(int x,int y,int n,int m)
{
    if(x>=0 && y>=0 && x<n && y<m)return true;
    else return false;
}
int main()
{
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                scanf("%d",&grid[i][j]);
                dp[i][j]=INT_MAX;
            }
        }
        priority_queue<edge,vector<edge>,greater<edge> >q;
        edge tmp;
        tmp.r=0;
        tmp.c=0;
        tmp.cost=dp[0][0]=grid[0][0];
        q.push(tmp);
        while(!q.empty())
        {
            tmp=q.top();
            q.pop();
            int x=tmp.r;
            int y=tmp.c;
            int w=tmp.cost;
            for(int i=0; i<4; i++)
            {
                int r=x+dx[i];
                int c=y+dy[i];
                if(isvalid(r,c,n,m) && dp[x][y]+grid[r][c]<dp[r][c])
                {
                    dp[r][c]=dp[x][y]+grid[r][c];
                    tmp.r=r;
                    tmp.c=c;
                    tmp.cost=dp[r][c];
                    q.push(tmp);
                }
            }
        }
        printf("%d\n",dp[n-1][m-1]);
    }
}
