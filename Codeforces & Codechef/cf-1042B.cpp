#include<bits/stdc++.h>
using namespace std;
map< string , vector<long long> >v;
int main()
{
    int n;
    cin >> n;
    map <string , int> mp;
    for(int i=0; i<n; i++)
    {
        string s;
        int val;
        cin>>val>>s;
        sort(s.begin(),s.end());
        s.erase(unique(s.begin(), s.end()), s.end());
        mp[s]=1;
        v[s].push_back(val);
    }
    for(auto it : mp)
    {
        //cout<<it.first<<endl;
        sort(v[it.first].begin(),v[it.first].end());
    }
    long long sum=1e18;
    if(mp.find("A")!=mp.end() && mp.find("B")!=mp.end() && mp.find("C")!=mp.end())
    {
        sum=min(sum,v["A"][0]+v["B"][0]+v["C"][0]);
    }
    if(mp.find("AB")!=mp.end() && mp.find("BC")!=mp.end())
    {
        sum=min(sum,v["AB"][0]+v["BC"][0]);
    }
    if(mp.find("AC")!=mp.end() && mp.find("AB")!=mp.end())
    {
        sum=min(sum,v["AC"][0]+v["AB"][0]);
    }
    if(mp.find("AC")!=mp.end() && mp.find("BC")!=mp.end())
    {
        sum=min(sum,v["AC"][0]+v["BC"][0]);
    }
    if(mp.find("A")!=mp.end() && mp.find("BC")!=mp.end())
    {
        sum=min(sum,v["A"][0]+v["BC"][0]);
    }
    if(mp.find("AB")!=mp.end() && mp.find("C")!=mp.end())
    {
        sum=min(sum,v["AB"][0]+v["C"][0]);
    }
    if(mp.find("AC")!=mp.end() && mp.find("B")!=mp.end())
    {
        sum=min(sum,v["AC"][0]+v["B"][0]);
    }
    if(mp.find("ABC")!=mp.end())
    {
        sum=min(sum,v["ABC"][0]);
    }
    if(sum==1e18)sum=-1;
    cout<<sum<<endl;
}

