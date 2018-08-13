#include<stdio.h>
int main()
{
    int test_case,ii;

    scanf("%d",&test_case);

    for(ii = 1; ii <= test_case; ii++)
    {
        double n;
        int x;

        scanf("%lf",&n);
        scanf("%d",&x);
        //we can solve this problem just 10 conditions. because x<=10.
        if(x==0)printf("%.0lf\n",n);
        if(x==1)printf("%.1lf\n",n);
        if(x==2)printf("%.2lf\n",n);
        if(x==3)printf("%.3lf\n",n);
        if(x==4)printf("%.4lf\n",n);
        if(x==5)printf("%.5lf\n",n);
        if(x==6)printf("%.6lf\n",n);
        if(x==7)printf("%.7lf\n",n);
        if(x==8)printf("%.8lf\n",n);
        if(x==9)printf("%.9lf\n",n);
        if(x==10)printf("%.10lf\n",n);
    }
}


