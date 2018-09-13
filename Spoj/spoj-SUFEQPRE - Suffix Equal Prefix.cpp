#include<bits/stdc++.h>
using namespace std;
int pref[1000001];
char s[1000001];
void kmp()
{
    int n=strlen(s);
    pref[0]=0;
    int i=1,j=0;
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
int main()
{
    int tt,kk=1;
    scanf("%d",&tt);
    while(tt--)
    {
        //memset(pref,0,sizeof pref);
        scanf("%s",s);
        kmp();
        int c=0;
//        for(int i=0; i<s.size(); i++)
//        {
//            cout<<pref[i]<<" ";
//        }
//        cout<<endl;
        int p=pref[strlen(s)-1];
        while(p!=0)
        {
            p=pref[p-1];
            c++;
        }
        printf("Case %d: %d\n",kk++,c);
    }
}
