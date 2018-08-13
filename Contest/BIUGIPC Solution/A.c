#include<stdio.h>
int main()
{
    int test_case,ii;

    scanf("%d",&test_case);

    for(ii = 1; ii <= test_case; ii++)
    {
        int n;
        scanf("%d",&n);
        if(n%2==0)printf("even\n");
        else printf("odd\n");
    }
}
