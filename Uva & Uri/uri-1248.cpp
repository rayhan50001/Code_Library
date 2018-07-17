#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    scanf("\n");
    while(tt--)
    {
        string a,b,c;
        getline(cin,a);
        getline(cin,b);
        getline(cin,c);
        map<char,int>mp1;
        map<char,int>mp2;
        for(int i=0; i<a.size(); i++)mp1[a[i]]=1;
        int hudai=0;
        for(int i=0; i<b.size(); i++)
        {
            if(mp1[b[i]]==0)
            {
                hudai=1;
                break;
            }
            mp2[b[i]]=1;
        }
        for(int i=0; i<c.size(); i++)
        {
            if(mp1[c[i]]==0)
            {
                hudai=1;
                break;
            }
            mp2[c[i]]=1;
        }
        string s;
        for(int i=0; i<a.size(); i++)
        {
            if(mp2[a[i]]==0)s+=a[i];
        }
        sort(s.begin(),s.end());
        if(hudai==1)cout<<"CHEATER\n";
        else cout<<s<<endl;
    }
}
