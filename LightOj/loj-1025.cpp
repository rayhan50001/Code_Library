#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[65][65];
ll solve(int i,int j,string s)
{
    if(i>j)return 0;
    if(i==j)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(s[i]==s[j])
    {
        return dp[i][j]=1+solve(i+1,j,s)+solve(i,j-1,s);
    }
    else
    {
        return dp[i][j]=solve(i+1,j,s)+solve(i,j-1,s)-solve(i+1,j-1,s);
    }
}
int main()
{
    int tt,kk=1;
    cin>>tt;
    while(tt--)
    {
        string s;
        cin>>s;
        memset(dp,-1,sizeof dp);
        ll res=solve(0,s.size()-1,s);
        printf("Case %d: %lld\n",kk++,res);
    }
}
