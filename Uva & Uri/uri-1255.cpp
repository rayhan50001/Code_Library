#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    scanf("\n");
    while(tt--)
    {
        string s;
        getline(cin,s);
        vector<char>v;
        map<char,int>mp;
        int mx=0;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==' ')continue;
            mp[s[i]]++;
            mx=max(mx,mp[s[i]]);
        }
        for(auto it:mp)
        {
            if(mx==it.second)v.push_back(it.first);
        }
        for(int i=0; i<v.size(); i++)cout<<v[i];
        cout<<endl;
    }
}
