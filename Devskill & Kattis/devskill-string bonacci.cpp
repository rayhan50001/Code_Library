#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll fib[1001];
ll solve(ll n,ll pos)
{

    if(n==0)return 0;
    if(n==1)return 1;
    //cout<<n<<" "<<pos<<" "<<fib[n-1]<<endl;
    if(pos<=fib[n-2])return solve(n-2,pos);
    else return solve(n-1,pos-fib[n-2]);
}
void pre()
{
    fib[0]=fib[1]=1;
    for(int i=2; i<=90; i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }
//    for(int i=0; i<=3; i++)cerr<<fib[i]<<" ";
//    cerr<<endl;
}
int main()
{
    pre();
    int tt,kk=1;
    cin>>tt;
    while(tt--)
    {
        ll n,pos;
        cin>>n>>pos;
        ll val=solve(n,pos);
        cout<<"Case "<<kk++<<": ";
        if(val==0)cout<<"a\n";
        else cout<<"b\n";
    }
}
