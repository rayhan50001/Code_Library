#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline bool isprime(int n)
{
    for(int i=2; i*i<=n; i++)if(n%i==0)return 0;
    return 1;
}
int main()
{
    int tt,kk=1;
    scanf("%d",&tt);
    while(tt--)
    {
        ll n;
        scanf("%lld",&n);
        ll sq=sqrt(n);
        //cout<<sq<<endl;
        printf("Case %d:",kk++);
        if(n>3 && isprime(n))
        {
            printf(" %d\n",n-1);
            continue;
        }

        for(ll i=sq-1; i>=1; i--)
        {
            ll val=n-i*i;
            if(val%i==0)printf(" %lld",val);
        }
        printf("\n");
    }
}
