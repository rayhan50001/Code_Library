#include<bits/stdc++.h>
using namespace std;
int dp[100001];
int n=20000;
bool check(int ans,int k)
{
    for(int i=ans; i<=n; i++)
    {
        int sum=dp[i]-dp[i-ans];
        if(sum>=k)return 1;
    }
    return 0;
}
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int k;
        cin>>k;
        vector<int>v;
        dp[0]=0;
        for(int i=1; i<=n; i++)
        {
            int x;
            cin>>x;
            dp[i]=dp[i-1]+x;
        }
        int l=1;
        int h=n;
        int ans=1e9;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(check(mid,k))
            {
                h=mid-1;
                ans=min(ans,mid);
            }
            else
            {
                l=mid+1;
            }
        }
        cout<<ans<<endl;
    }
}
