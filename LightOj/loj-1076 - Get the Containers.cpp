//GREEDY BINARY SEARCH :P :) :D

#include<bits/stdc++.h>
using namespace std;
int arr[1000001];
int check(int ans,int k,int n)
{
    int sum=0;
    int c=1;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        if(sum>ans)
        {
            sum=arr[i];
            c++;
        }
    }
    return (c<=k);
}
int main()
{
    //freopen("out.txt","w",stdout);
    int tt,kk=1;
    scanf("%d",&tt);
    while(tt--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        int l=0,h=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&arr[i]);
            h+=arr[i];
        }
        l=*max_element(arr,arr+n);
        int ans=0;
        while(l<=h)
        {
            //cout<<l<<" "<<h<<endl;
            int mid=(l+h)/2;
            if(check(mid,k,n))
            {
                h=mid-1;
                ans=mid;
            }
            else l=mid+1;
        }
        printf("Case %d: %d\n",kk++,ans);
    }
}
