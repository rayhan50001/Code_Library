#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#define maxv 200000000
#define limit maxv/15
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
#define ll long long
unsigned int pbits[limit/32+1];
int prime[prr];
int len;
void sieve( void )
{
  int i, j, mx = (int) sqrt( limit );
  len = 0;
  for( i = 3; i < limit; i += 2)
    if( !PHAS(i) )
    {
      prime[len++] = i;
      if( i <= mx )
        for( j = i*i; j <= limit; j += 2*i) PSET(j);
    }
}
char chk[BITNSLOTS(maxv+1)]={'\0'};
int ch_no[charming];
int sz;
void calc()
{
    //memset(chk, 0, BITNSLOTS(limit));
	int i, j, k;
     int lenn=584;
   for(i=0; i<=lenn; i++)
   {
       int first_len=(ll)sqrt((double)maxv/(double)prime[i]);
       for(j=i+1; prime[j]<=first_len && j<len; j++)
       {
               int t=prime[i]*prime[j];
               int second_len=(ll)((double)maxv/(double)t);
               for(k=j+1; prime[k]<=second_len && k<len; k++)
               {
                     BITSET(chk,t*prime[k]);
               }
       }
   }
    for(i=1; i<=maxv; i+=2)
    {
        if(BITTEST(chk,i))ch_no[sz++]=i;
    }
}
int lowerBound(int lo, int hi, int x)
{
    if(lo > hi)
     return hi;
   int mid = (lo + hi) / 2;
   if(ch_no[mid] == x)
    return lowerBound(lo, mid-1, x);
   else if (ch_no[mid] > x)
    return lowerBound(lo, mid-1, x);
   else
    return lowerBound(mid+1, hi, x);
}
int upperBound(int lo,int hi, int x)
{
    if(lo > hi)
     return lo;
   int mid = (lo + hi) / 2;
   if(ch_no[mid] == x)
    return upperBound(mid+1, hi, x);
   else if (ch_no[mid] > x)
    return upperBound(lo, mid-1, x);
   else
    return upperBound(mid+1, hi, x);
}

int main()
{
    sieve();
    calc();
    printf("%d %d",prime[len-1],len);
    int tt,kk=1;
    scanf("%d",&tt);
    while(tt--)
    {
        int l,r;
        scanf("%d %d",&l,&r);
        int low=lowerBound(0,sz-1,l);
        int high=upperBound(0,sz-1,r);
        printf("Case %d: %d\n",kk++,high-low-1);
    }
}
