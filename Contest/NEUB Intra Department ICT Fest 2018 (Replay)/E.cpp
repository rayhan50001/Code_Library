#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    while(q--)
    {
        string s;
        cin>>s;
        string nn;
        for(int i=1; i<s.size(); i++)nn+=s[i];
        int num=atoi(nn.c_str());
        if(s[0]=='R')
        {
            cout<<"("<<num<<","<<m<<")";
            for(int i=m-1; i>=1; i--)
            {
                cout<<", ";
                cout<<"("<<num<<","<<i<<")";
            }
        }
        if(s[0]=='U')
        {
            cout<<"("<<1<<","<<num<<")";
            for(int i=2; i<=n; i++)
            {
                cout<<", ";
                cout<<"("<<i<<","<<num<<")";
            }
        }
        if(s[0]=='L')
        {
            cout<<"("<<num<<","<<1<<")";
            for(int i=2; i<=m; i++)
            {
                cout<<", ";
                cout<<"("<<num<<","<<i<<")";
            }
        }
        if(s[0]=='D')
        {
            cout<<"("<<n<<","<<num<<")";
            for(int i=n-1; i>=1; i--)
            {
                cout<<", ";
                cout<<"("<<i<<","<<num<<")";
            }
        }
        cout<<endl;
    }
}
