#include<bits/stdc++.h>
using namespace std;
vector<int>v[5];
int main()
{
    map<char,int>mp;
    mp['G']=1;
    mp['D']=2;
    mp['M']=3;
    mp['F']=4;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        char ch;
        int x;
        cin>>ch>>x;
        v[mp[ch]].push_back(x);
    }
    vector<int>ans;
    long long sum=0;
    for(int i=1; i<=4; i++)
    {
        sort(v[i].begin(),v[i].end());
        //cout<<v[i].size()<<" ";
        if(i==1)
        {
            sum+=v[i].back();
            v[i].pop_back();
        }
        else if(i==2)
        {
            sum+=v[i].back();
            v[i].pop_back();
            sum+=v[i].back();
            v[i].pop_back();
        }
        else if(i==3)
        {
            sum+=v[i].back();
            v[i].pop_back();
            sum+=v[i].back();
            v[i].pop_back();
        }
        else
        {
            sum+=v[i].back();
            v[i].pop_back();
        }
    }
    //cout<<sum<<endl;
    for(int i=2; i<=4; i++)
    {
        //cout<<v[i].size()<<" ";
        for(int j=0; j<v[i].size(); j++)ans.push_back(v[i][j]);
    }
    sort(ans.begin(),ans.end());
    int left=5;
    while(left--)
    {
        sum+=ans.back();
        //cout<<sum<<endl;
        ans.pop_back();
    }
    cout<<sum<<endl;

}
