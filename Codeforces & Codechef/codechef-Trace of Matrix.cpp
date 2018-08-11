#include<bits/stdc++.h>
using namespace std;
int grid[1001][1001];
int arr[100001];
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        memset(arr,0,sizeof arr);
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>grid[i][j];
            }
        }
        arr[4*n]=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                arr[n+i-j]+=grid[i][j];
            }
        }
        int mx=0;
        for(int i=0; i<4*n; i++)
        {
            mx=max(mx,arr[i]);
        }
        cout<<mx<<endl;
    }
}
