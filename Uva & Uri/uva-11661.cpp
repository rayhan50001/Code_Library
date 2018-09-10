#include<bits/stdc++.h>
using namespace std;
char s[2000001];
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        scanf("%s",s);
        int lastD=-1;
        int lastR=-1;
        int mn=1e9;
        for(int i=0; i<n; i++)
        {
            //cout<<lastR<<" "<<lastD<<endl;
            if(s[i]=='Z')
            {
                mn=0;
            }
            if(s[i]=='R')
            {
                lastR=i+1;
                if(lastR>0 && lastD>0)
                {
                    mn=min(mn,abs(lastR-lastD));
                }
            }
            else if(s[i]=='D')
            {
                lastD=i+1;
                if(lastR>0 && lastD>0)
                {
                    mn=min(mn,abs(lastR-lastD));
                }
            }
        }
        printf("%d\n",mn);
    }
}
