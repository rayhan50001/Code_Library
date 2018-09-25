#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>v;
    int x,y,z;
    cin>>x>>y>>z;
    v.push_back(x);
    v.push_back(y);
    v.push_back(z);
    sort(v.begin(),v.end());
    int mn=min(v[1]-v[0],v[2]-v[1]);
    if(v[1]-v[0]==mn && v[2]-v[1]==mn)cout<<v[2]+mn<<endl;
    else if(v[1]-v[0]==mn)cout<<v[1]+mn<<endl;
    else cout<<v[0]+mn<<endl;

}
