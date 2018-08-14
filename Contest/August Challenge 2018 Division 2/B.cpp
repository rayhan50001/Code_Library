#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    vector<ll>v;
    for(ll i=0; i<32; i++)
    {
        for(ll j=i+1; j<32; j++)
        {
            ll val1=powl(2LL,i);
            ll val2=powl(2LL,j);
            v.push_back((val1+val2));
        }
    }
    sort(v.begin(),v.end());
    int tt;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        int idx=lower_bound(v.begin(),v.end(),n)-v.begin();
        ll ans=min(abs(n-v[idx]),abs(n-v[idx-1]));
        cout<<ans<<endl;
    }
}
