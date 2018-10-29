#include<bits/stdc++.h>
using namespace std;
int arr[1000001];
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>arr[i];
        bool paisi=0;
        int breakpoint=-1;
        for(int i=1; i<n; i++)
        {
            if(arr[i]>=arr[i-1])continue;
            breakpoint=i;
            break;
        }
        if(breakpoint==-1)cout<<"YES\n";
        else
        {
            for(int i=breakpoint+1; i<n; i++)
            {
                if(arr[i]>=arr[i-1] && arr[i]<=arr[0] && arr[i-1]<=arr[0])continue;
                paisi=1;
                break;
            }
            if(!paisi)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}

