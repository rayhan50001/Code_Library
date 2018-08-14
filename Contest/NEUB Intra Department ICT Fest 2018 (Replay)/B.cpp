#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt,kk=1;
    cin>>tt;
    while(tt--)
    {
        long long v,e;
        cin>>v>>e;
        long long f=2+abs(e-v);
        f=abs(f);
        cout<<"Case "<<kk++<<": "<<f<<endl;
    }
}
