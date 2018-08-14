#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int main()
{
    int tt,kk=1;
    cin>>tt;
    while(tt--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        while(q--)
        {
            int t,x,y;
            cin>>t>>x>>y;
            if(t==1)
            {
                for(int i=0; i<n; i++)
                    if(arr[i]<=x)arr[i]-=y;
            }
            else
            {
                for(int i=0; i<n; i++)
                    if(arr[i]>=x)arr[i]+=y;
            }
        }
        for(int i=0; i<n; i++)
        {
            cout<<arr[i];
            if(i<n-1)cout<<" ";
        }
        cout<<endl;
    }
}
