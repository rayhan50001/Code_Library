#include<bits/stdc++.h>
using namespace std;
int arr[1000001];
int cum[1000001];
int ans[1000001];
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        memset(ans,0,sizeof ans);
        int n,s;
        cin>>n>>s;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int sum=0;
        do{
            for(int i = 0; i < n; i++)
            {
                int num1 = 0, num2 = 0;
                for(int j = 0; j < i; j++)
                {
                    sum = arr[i];
                    for(int k = j; k < i; k++)
                    {
                        sum+= arr[k];
                    }
                    if(sum >= s)
                    {
                        num1++;
                    }
                }

                for(int j = n-1; j > i; j--)
                {
                    sum = arr[i];
                    for(int k = j; k > i; k--)
                    {
                        sum+= arr[k];
                    }
                    if(sum >= s)
                    {
                        num2++;
                    }
                }
                int res = num1 + num2;
                if(arr[i] >= s)
                {
                    res++;
                }
                ans[i] = max(ans[i],res);
            }

        }while(next_permutation(arr,arr+n));
        for(int i=0; i<n; i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
}
