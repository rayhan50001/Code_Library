#include<bits/stdc++.h>
using namespace std;
int dist[1001][1001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int grid[1001][1001];
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>grid[i][j];
                dist[i][j]=1e8;
            }
        }
        priority_queue<
    }
}
