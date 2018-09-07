#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[]={1,2,4};
int main()
{
    int tt,kk=1;
    cin>>tt;
    while(tt--)
    {
    ll n;
    cin>>n;
    cout<<arr[n%3LL]<<endl;
    }
}

