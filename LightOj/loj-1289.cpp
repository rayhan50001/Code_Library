#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#define maxv 100000001
#define limit maxv
#define prr 869515
#define charming 26825909
#define PHAS(_n) (pbits[(_n)>>5] & (1u << ((_n) & 0x1f)))
#define PSET(_n) (pbits[(_n)>>5] |= (1u << ((_n) & 0x1f)))
#define BITMASK(b) (1 << ((b) % CHAR_BIT))
#define BITSLOT(b) ((b) / CHAR_BIT)
#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITCLEAR(a, b) ((a)[BITSLOT(b)] &= ~BITMASK(b))
#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))
#define BITNSLOTS(nb) ((nb + CHAR_BIT - 1) / CHAR_BIT)
#define ll unsigned int
#define MAX 100000000//max num to prime
#define LMT 10010 //sqrt(MAX)

int flag[MAX/64];
unsigned int prime[5761459],MOD;
int total;

#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))
unsigned int pwr[5761459];
void sieve()
{
    int i,j,k;

    flag[0]|=0;
    for(i=3;i<LMT;i+=2)
        if(!chkC(i))
            for(j=i*i,k=i<<1;j<MAX;j+=k)
                setC(j);

    prime[(j=0)] = 2;//prime starts from 0 position
    pwr[(j=0)++]=2;
    for(i=3;i<MAX;i+=2)
        if(!chkC(i))
        {
            prime[j] = i;
            pwr[j]=pwr[j-1]*i;
            j++;
            //printf("%d\n",primes[j-1]);
        }
    total = j-1;
}
unsigned int LCM(unsigned int n,unsigned int MOD)
{
    unsigned int lcm = 1;
    for(ll i=0; prime[i]*prime[i]<=n; i++)
    {
        unsigned int pp=n;
        pp = pp/prime[i];
        while(prime[i]<=pp)
        {
            pp=pp/prime[i];
            lcm=(lcm*prime[i]);
        }
    }
    return lcm;
}
int upperBound(int lo,int hi, unsigned int x)
{
    if(lo > hi)
     return lo;
   int mid = (lo + hi) / 2;
   if(prime[mid] == x)
    return upperBound(mid+1, hi, x);
   else if (prime[mid] > x)
    return upperBound(lo, mid-1, x);
   else
    return upperBound(mid+1, hi, x);
}
int main()
{
    //freopen("out.txt","w",stdout);
    MOD=1LL<<32;
    //printf("%lld\n",MOD);
    sieve();
    //printf("%d",total);
    int tt,kk=1;
    scanf("%d",&tt);
    while(tt--)
    {
        unsigned int n;
        scanf("%u",&n);
        unsigned int ans=LCM(n,MOD);
        int idx=upperBound(0,total,n);
        //printf("%d %lld\n",idx,prime[idx]);
        ans=ans*pwr[idx-1];
        printf("Case %d: %u\n",kk++,ans);
    }
}
