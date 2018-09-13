#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int main()
{
    int tt,kk=1;
    scanf("%d",&tt);
    while(tt--)
    {
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        printf("Case %d:\n",kk++);
        while(q--)
        {
            int l,r;
            scanf("%d %d",&l,&r);
            int low=lower_bound(arr,arr+n,l)-arr;
            int high=upper_bound(arr,arr+n,r)-arr;
            printf("%d\n",high-low);
        }
    }
}
