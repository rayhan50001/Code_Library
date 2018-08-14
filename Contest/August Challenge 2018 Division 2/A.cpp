#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        string s1,s2;
        cin>>s1>>s2;
        int b[10],o[10];
        memset(b,0,sizeof b);
        memset(o,0,sizeof o);
        for(int i=0; i<s1.size(); i++)
        {
            if(s1[i]=='b' || s2[i]=='b')b[i]=1;
            if(s1[i]=='o' || s2[i]=='o')o[i]=1;
        }
        if((b[0]==1 && o[1]==1 && b[2]==1) || (b[1]==1 && o[0]==1 && b[2]==1) ||(b[0]==1 && o[2]==1 && b[1]==1))cout<<"yes\n";
        else cout<<"no\n";
    }
}
