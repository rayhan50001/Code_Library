#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    map<char,int>mp;
    for(int i=0; i<n; i++)mp[s[i]]++;
    int ans=0;
    if(k==mp.size())
    {
        int mn=1e9;
        for(auto it:mp)
            mn=min(mn,it.second);
        ans=mn*k;
    }
    cout<<ans<<endl;
}
