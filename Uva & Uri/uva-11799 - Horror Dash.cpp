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
        cout<<*max_element(arr,arr+n)<<endl;
    }
}
