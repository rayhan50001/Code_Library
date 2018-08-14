#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen("in.txt","w",stdout);
    int t=1;
    cout<<t<<endl;
    for(int i=0; i<t; i++)
    {
        ll n=25;
        ll s=1e9;
        cout<<n<<" "<<s<<endl;
        for(int j=0; j<n; j++)
        {
            cout<<rand()%1000000000<<" ";
        }
        cout<<endl;
    }
}

