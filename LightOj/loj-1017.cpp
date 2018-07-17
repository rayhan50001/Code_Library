
#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int dp[101][101];
int solve(int pos,int move,int n,int k,int w)
{
    if(pos>=n || move>=k)return 0;
    if(dp[pos][move]!=-1)return dp[pos][move];
    int c=0,i=0;
    for(i=0; i+pos<n; i++)
    {
        if(v[i+pos]-v[pos]<=w)c++;
        else break;
    }
    return dp[pos][move]=max(c+solve(pos+i,move+1,n,k,w),solve(pos+1,move,n,k,w));//niye next move or move na diye next position
}
int main()
{
    //freopen("out.txt","w",stdout);
    int tt,kk=1;
    cin>>tt;
    while(tt--)
    {
        memset(dp,-1,sizeof dp);
        v.clear();
        int n,w,k;
        cin>>n>>w>>k;
        for(int i=0; i<n; i++)
        {
         int x,y;
         cin>>x>>y;
         v.push_back(y);
        }
        sort(v.begin(),v.end());
		int res=solve(0,0,n,k,w);
		printf("Case %d: %d\n",kk++,res);
    }
}
