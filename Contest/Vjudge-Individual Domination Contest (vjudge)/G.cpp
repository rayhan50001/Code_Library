#include<bits/stdc++.h>
using namespace std;
string Sum(string a, string b)
{
    if(a.size() < b.size())
        swap(a, b);

    int j = a.size()-1;
    for(int i=b.size()-1; i>=0; i--, j--)
        a[j]+=(b[i]-'0');

    for(int i=a.size()-1; i>0; i--)
        if(a[i] > '9')
        {
            int d = a[i]-'0';
            a[i-1] = ((a[i-1]-'0') + d/10) + '0';
            a[i] = (d%10)+'0';
        }
    if(a[0] > '9')
    {
        string k;
        k+=a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        a = k+a;
    }
    return a;
}
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        string a,b;
        cin>>a>>b;
        int i=0;
        while(a[i]=='0')i++;
        a=a.substr(i,a.size());
        i=0;
        while(b[i]=='0')i++;
        b=b.substr(i,b.size());
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        string ans=Sum(a,b);
        reverse(ans.begin(),ans.end());
        i=0;
        while(ans[i]=='0')i++;
        ans=ans.substr(i,ans.size());
        cout<<ans<<endl;
    }
}
