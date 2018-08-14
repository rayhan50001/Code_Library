#include<bits/stdc++.h>
using namespace std;
int arr[1000009];
int mypos=1;
int myfriend=1000000;
int main()
{
    int n;
    cin>>n;
    int mx1=0;
    int mx2=1000000;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        int val1=arr[i]-mypos;
        int val2=myfriend-arr[i];
        if(val1<val2)
        {
            mx1=max(arr[i],mx1);
        }
        else mx2=min(arr[i],mx2);
    }
    if(mx2==0)mx2=1000000;
    if(mx1==0)mx1=1;
    int ans=max(mx1-1,1000000-mx2);
    cout<<ans<<endl;
    return 0;
}

