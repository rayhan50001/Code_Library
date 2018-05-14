#include<stdio.h>
int arr[1000009];
int brr[1000009];
int main()
{
    int n;
    scanf("%d",&n);
    int all_z=0,all_o=0;
    int i,j,k=0;
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]==1)all_o+=1;
        else all_z+=1;
    }
    if(all_o==n || all_z==n)
    {
        printf("YES\n");
        return 0;
    }
    for(i=0; i<n; i++)
    {
        int c=0;
        for(j=i; j<n; j++)
        {
            if(arr[i]==arr[j])c++;
            else break;
        }
        brr[k]=c;
        i+=(c-1);
        k++;
    }
    int f=0;
    int val=brr[0];
    for(i=1; i<k; i++)
    {
        if(val!=brr[i])
        {
            f=1;
            break;
        }
    }
    if(!f)
        printf("YES\n");
    else printf("NO\n");


}
