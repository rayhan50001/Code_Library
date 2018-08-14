#include<stdio.h>
int main()
{
	int tt,kk=1;
	scanf("%d",&tt);
	while(tt--)
	{
	    int a,b;
	    scanf("%d %d",&a,&b);
	    printf("Case %d: %d\n",kk++,a*a+b*b);
	}
}
