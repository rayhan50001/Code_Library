#include<bits/stdc++.h>
using namespace std;
int main()
{
        long long n,q;
        scanf("%lld %lld",&n,&q);
        while(q--)
        {
            long long x,y;
            scanf("%lld %lld",&x,&y);
            if(x%2==1 && y%2==1)
            {
               long long age_x=(x-1);
               long long even=age_x/2;
               long long odd=age_x/2;
               even=even*(n/2);
               odd=odd*(n/2+n%2);
               long long ans=even+odd+(y/2+y%2);
               printf("%lld\n",ans);
            }
            else if(x%2==1 && y%2==0)
            {
               long long age_x=(x-1);
               long long even=age_x/2;
               long long odd=age_x/2;
               even=even*(n/2+n%2);
               odd=odd*(n/2);
               long long nn=n*n;
               long long ans=even+odd+nn/2+nn%2+y/2;
               printf("%lld\n",ans);
            }
            else if(x%2==0 && y%2==0)
            {
               long long age_x=(x-1);
               long long even=age_x/2+age_x%2;
               long long odd=age_x/2;
               even=even*(n/2+n%2);
               odd=odd*(n/2);
               long long ans=even+odd+(y/2);
               printf("%lld\n",ans);
            }
            else if(x%2==0 && y%2==1)
            {
               long long age_x=(x-1);
               long long even=age_x/2+age_x%2;
               long long odd=age_x/2;
               even=even*(n/2);
               odd=odd*(n/2+n%2);
               //cout<<even<<" "<<odd<<endl;
               long long nn=n*n;
               long long ans=even+odd+nn/2+nn%2+y/2+y%2;
               printf("%lld\n",ans);
            }
        }
}
