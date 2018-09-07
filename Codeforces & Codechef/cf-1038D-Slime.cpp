#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin>>n;
    vector<ll>v;
    ll sum=0;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    if(n==1)cout<<v[0]<<endl;
    else
    {
        for(int i=0; i<n; i++)
        {
            if(i==0)
            {
                sum+=v[i]>0? -v[i]:abs(v[i]);
            }
            else if(i+1==n)
            {
                sum+=v[i];
            }
            else
            {
                sum+=abs(v[i]);
            }
        }
        cout<<sum<<endl;
    }


}
