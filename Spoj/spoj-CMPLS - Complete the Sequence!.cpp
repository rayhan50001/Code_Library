//forward difference (numerical analysis)
#include<stdio.h>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define f(x) sin(x)
int dp[1000][1000];
int calculate(int l)
{
     for(int j=1; j<l; j++)
     {
        for(int i=0; i<l-j; i++)
        {
            dp[i][j]=(dp[i+1][j-1]-dp[i][j-1]);
        }
    }
    int ans=0;
    for(int j=0; j<l; j++)
    {
       ans+=dp[j][l-j-1];
    }
    return ans;
}
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
    memset(dp,0,sizeof dp);
    int n,c;
    cin>>n>>c;
    int l=0;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        dp[l][0]=x;
        //cout<<f<<" ";
        l++;
    }
    vector<int>ans;
    for(int i=l; i<l+c; i++)
    {
        int res=calculate(i);
        ans.push_back(res);
        dp[i][0]=res;
    }
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i];
        if(ans.size()-1>i)cout<<" ";
    }
    cout<<endl;
    }
}
