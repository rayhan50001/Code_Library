#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        int n;
        scanf("%d",&n);
        int past=-1;
        int morse=0;
        for(int i=0; i<n; i++)
        {
            int x;
            scanf("%d",&x);
            if(past==-1)past=x;
            else
            {
                int val=abs(past-x);
                if(val%2==1)morse=1;
            }
        }
        if(morse==0)printf("yes\n");
        else printf("no\n");
    }
}
