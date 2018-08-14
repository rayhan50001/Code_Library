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
        int now=1;
        int increas=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i]==now)
            {
                now++;
            }
            else increas++;
        }
        cout<<"Case "<<kk++<<": ";
        cout<<increas<<endl;
    }
}
