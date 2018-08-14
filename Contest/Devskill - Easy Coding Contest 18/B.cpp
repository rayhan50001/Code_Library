#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt;
    cin>>tt;
    while(tt--){
     vector<pair<int,string> >v;
     int n;
     cin>>n;
     for(int i=0; i<n; i++)
     {
         string s;
         int g;
         cin>>s>>g;
         v.push_back({g,s});
     }
     sort(v.begin(),v.end());
     cout<<"Winner: "<<"\\"<<v[v.size()-1].second<<"/"<<endl;
    }

}

