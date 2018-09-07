#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        map<int,int>mp;
        int n;
        cin>>n;
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            if(mp[x])ans=x;
            mp[x]=1;
        }
        cout<<ans<<endl;
    }
}
