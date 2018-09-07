#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
       int n;
       cin>>n;
       if(n==1)cout<<3<<endl;
       else if(n==2)cout<<12<<endl;
       else
       {
           cout<<1;
           for(int i=2; i<=n-1; i++)cout<<0;
           cout<<2<<endl;
       }
    }
}
