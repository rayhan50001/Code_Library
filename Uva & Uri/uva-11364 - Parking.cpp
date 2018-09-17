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
        int lo=*min_element(arr,arr+n);
        int hi=*max_element(arr,arr+n);
        cout<<(hi-lo)*2<<endl;
    }
}

