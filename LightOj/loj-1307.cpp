#include<bits/stdc++.h>
using namespace std;
int arr[10001];
bool check(int x,int y,int z)
{
    if(x+y>z && x+z>y && y+z>x)return true;
    else return false;
}
int main()
{
    int tt,kk=1;
    scanf("%d",&tt);
    while(tt--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int sum = arr[i]+arr[j];
                int idx = lower_bound(arr,arr+n,sum)-arr;
                //cout<<arr[i]<<" "<<arr[j]<<" "<<arr[idx]<<" "<<idx-j-1<<endl;
                //idx=min(n-1,idx);
                if(idx>j)ans+=idx-j-1;
            }
        }
        printf("Case %d: %d\n",kk++,ans);
    }
}
