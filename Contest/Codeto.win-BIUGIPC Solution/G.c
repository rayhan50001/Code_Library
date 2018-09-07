#include<stdio.h>

int main()
{
    int test_case,ii;
    scanf("%d",&test_case);
    for(ii = 1; ii <= test_case; ii++)
    {
        char s[1001];
        scanf("%s", s);
        int i,j,len;
        len=strlen(s);

        for( i=0; i<len; i++)
        {
            int c=0;
            for(j=i; j<len; j++)
            {
                if(s[i]==s[j])c=c+1;
                else break;
            }
            if(c<=2)printf("%c",s[i]);
            else
            {
                i+=(c-1);
                printf("%d",c);
                printf("%c",s[i]);
            }
        }
        printf("\n");
    }
}


