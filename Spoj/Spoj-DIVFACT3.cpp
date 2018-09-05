#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100000001
bitset<100000009>isprime;
vector<ll>prime;
vector<ll>SPF(N);
void sieve()
{
    isprime[0] = 1;
	isprime[1] = 1;
    for (ll i=2; i<N ; i++)
    {
        if (isprime.test(i)==false)
        {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (ll j=0; j < (ll)prime.size() && i*prime[j] < N && prime[j] <= SPF[i]; j++)
        {
            isprime[i*prime[j]]=1;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}
int main()
{
    sieve();
    ll tt;
    scanf("%lld",&tt);
    while(tt--)
    {
        ll n,m;
        scanf("%lld %lld",&n,&m);
        long long ans=1;
        for(ll i=0; i<prime.size(); i++)
        {
            if(prime[i]>n)break;
            long long c=0;
            ll nn=n;
            while(nn>0)
            {
                nn/=prime[i];
                c+=nn;
            }
            ans=(ans%m*(c+1)%m)%m;
            if(ans<0)ans+=m;
        }
        printf("%lld\n",ans);
    }
}
