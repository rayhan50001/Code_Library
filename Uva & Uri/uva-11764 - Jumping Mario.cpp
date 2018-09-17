#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int main()
{
    int tt,kk=1;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cout<<"Case "<<kk++<<": ";
        int hi=0,lo=0;
        for(int i=1; i<n; i++)
        {
            if(arr[i]>arr[i-1])hi++;
            if(arr[i]<arr[i-1])lo++;
        }
        cout<<hi<<" "<<lo<<endl;
    }
}
