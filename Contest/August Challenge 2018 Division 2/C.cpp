#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>p1,pair<int,int>p2)
{
    if(p1.first==p2.first)
    {
        return p1.second<p2.second;
    }
    return p1.first<p2.first;
}
int main()
{
    int p,s;
    cin>>p>>s;
    vector<pair<int,int> >ans;
    for(int i=0; i<p; i++)
    {
        vector<int>sc;
        vector<pair<int,int> >ns;
        for(int j=0; j<s; j++)
        {
            int x;
            cin>>x;
            sc.push_back(x);
        }
        for(int j=0; j<s; j++)
        {
            int x;
            cin>>x;
            ns.push_back({sc[j],x});
        }
        sort(ns.begin(),ns.end());
        int cc=0;
        for(int i=1; i<ns.size(); i++)
        {
            if(ns[i-1].second>ns[i].second)cc++;
        }
        ans.push_back({cc,i+1});
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].second<<endl;
    }

}
