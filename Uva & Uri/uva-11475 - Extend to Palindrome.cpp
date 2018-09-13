#include<bits/stdc++.h>
using namespace std;
char s[1000001];
char pat[1000001];
int pref[1000001];
void kmp()
{
    int i=1,j=0;
    int n=strlen(s);
    pref[0]=0;
    while(i<n)
    {
        if(s[i]==s[j])
        {
            j++;
            pref[i]=j;
            i++;
        }
        else
        {
            if(j!=0)
            {
                j=pref[j-1];
            }
            else
            {
                pref[i]=0;
                i++;
            }
        }
    }
}
int match()
{
    int n=strlen(s);
    int m=n;
    int i=0,j=0;
    while(i<n)
    {
        if(pat[i]==s[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=pref[j-1];
            }
            else
            {
                j=0;
                i++;
            }
        }
    }
    return j;
}
int main()
{
    int tt,kk=1;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%s",s);
        reverse(s,s+strlen(s));
        int j=0;
        for(int i=strlen(s)-1; i>=0; i--)
        {
            pat[j++]=s[i];
        }
        kmp();
        int n=strlen(s);
        int mat=match();
        printf("Case %d: %d",kk++,n+(n-mat));
        printf("\n");
    }
}
