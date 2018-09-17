#include<bits/stdc++.h>
using namespace std;
string s[17]={"Happy", "birthday" ,"to", "you" ,"Happy", "birthday", "to" ,"you" ,"Happy", "birthday", "to", "Rujia","Happy" ,"birthday" ,"to", "you"};
int main()
{
    int n;
    cin>>n;
    vector<string>v;
    for(int i=0; i<n; i++)
    {
        string ss;
        cin>>ss;
        v.push_back(ss);
    }
    int len=16*(n/16+((n%16)?1:0));
    for(int i=0; i<len; i++)
    {
        cout<<v[i%n]<<": "<<s[i%16]<<endl;
    }
}
