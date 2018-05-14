#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int tt,k=1;
    cin>>tt;
    while(tt--)
    {
        long e,d,k;
        cin>>e>>d>>k;
        cout<<"Case "<<k++<<": ";
        if(d<=e)cout<<"Foot\n";
        else if(d<e*k)cout<<"Rickshaw\n";
        else cout<<"Crying\n";
    }
}
