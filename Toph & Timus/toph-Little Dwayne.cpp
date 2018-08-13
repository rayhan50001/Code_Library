#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int sum=0,n,k;
        cin>>n>>k;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            sum+=max(0,x-k);
        }
        cout<<sum<<endl;
    }
}
