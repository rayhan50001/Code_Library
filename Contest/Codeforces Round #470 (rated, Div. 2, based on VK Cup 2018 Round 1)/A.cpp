#include<bits/stdc++.h>
using namespace std;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
char grid[501][501];
bool isvalid(int x,int y,int n,int m)
{
    if(x>=0 && x<n && y>=0 && y<m)return true;
    else return false;
}
int main()
{
    int r,c;
    cin>>r>>c;
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin>>grid[i][j];
        }
    }
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grid[i][j]=='W')
            {
                for(int k=0; k<4; k++)
                {
                    int rr=dx[k]+i;
                    int cc=dy[k]+j;
                    if(isvalid(rr,cc,r,c) && grid[rr][cc]=='S')
                    {
                        cout<<"No\n";
                        return 0;
                    }
                }
            }
        }
    }
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(grid[i][j]=='S')
            {
                for(int k=0; k<4; k++)
                {
                    int rr=dx[k]+i;
                    int cc=dy[k]+j;
                    if(isvalid(rr,cc,r,c) && grid[rr][cc]=='.')
                    {
                        grid[rr][cc]='D';
                    }
                }
            }
        }
    }
    cout<<"Yes\n";
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}
