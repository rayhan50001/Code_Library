#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long k=1;
    for(int i=0; i<t; i++)
    {
        long long n;
        cin>>n;
        long long a=0,b=0,mn=1e9,aa=0,bb=0;
        for(long long i=0; i<=n; i++)
        {
            a=i*i;
            b=n*n-i*i;
            long long sq=sqrt(b);
            if(sq*sq==b && a+b==n*n)
            {
                a=sqrt(a);
                b=sqrt(b);
                if(abs(a-b)<mn)
                {
                    aa=a;
                    bb=b;
                    mn=abs(a-b);
                }
            }
        }
        printf("Case %lld: %lld %lld %lld\n",k++,aa,bb,n);
    }
}
