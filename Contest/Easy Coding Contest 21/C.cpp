#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
bool cmp(pair<int,string>p1, pair<int,string>p2)
{
    if(p1.first==p2.first)
    {
        return p1.second<p2.second;
    }
    else return p1.first>p2.first;
}
int main()
{
    mp[1]=1;
    mp[2]=1;
    mp[3]=3;
    mp[4]=3;
    mp[5]=5;
    mp[6]=5;
    mp[7]=2;
    mp[8]=2;
    mp[9]=8;
    mp[10]=8;
    int n;
    cin>>n;
    vector<pair<int,string> >v;
    for(int i=0; i<n; i++)
    {
        string s;
        int sl;
        cin>>s>>sl;
        int sum=0;
        for(int j=0; j<sl; j++)
        {
            int x;
            cin>>x;
            sum+=mp[x];
        }
        v.push_back({sum,s});
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0; i<n; ++i)
    {
        cout<<v[i].second<<endl;
    }
}

