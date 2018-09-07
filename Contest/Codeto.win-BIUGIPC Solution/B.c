#include<stdio.h>
int main()
{
    int test_case,ii;

    scanf("%d",&test_case);

    for(ii = 1; ii <= test_case; ii++)
    {
        int n,i;
        scanf("%d",&n);
        int sum=0;
        for(i = 1; i <= n; i++)
        {
            int number;
            scanf("%d",&number);
            sum=sum+number;
        }
        printf("%d\n",sum);
    }
}

