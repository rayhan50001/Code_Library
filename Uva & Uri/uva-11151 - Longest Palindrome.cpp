#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
string s;
int solve(int l, int r)
{
    if(l==r)return 1;
    if(l+1==r)
    {
        if(s[l]==s[r])return 2;
        else return 1;
    }
    if(dp[l][r]!=-1)return dp[l][r];
    int ans=0;
    if(s[l]==s[r])
    {
        ans=2+solve(l+1,r-1);
    }
    else
    {
        ans=max(solve(l+1,r),solve(l,r-1));
    }
    return dp[l][r]=ans;
}
int main()
{
    int tt;
    cin>>tt;
    getchar();
    while(tt--)
    {
        getline(cin,s);
        if(s.empty())cout<<0<<endl;
        else
        {
            memset(dp,-1,sizeof dp);
            int ans=solve(0,s.size()-1);
            cout<<ans<<endl;
        }
    }
}
