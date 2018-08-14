#include<stdio.h>
int main()
{
	int tt;
	scanf("%d",&tt);
	while(tt--)
	{
	    int n;
	    scanf("%d",&n);
	    if(n%2==0)printf("YES\n");
	    else printf("NO\n");
	}
}
