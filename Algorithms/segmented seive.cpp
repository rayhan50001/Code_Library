#include <cstdio>
#include <cstring>
#include <cmath>

#define MAX 46656
#define LMT 216
#define LEN 4830
#define RNG 100032

int base[MAX>>6], segment[RNG>>6], primes[LEN], prlen,flag[RNG];

#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))

void sieve() {
	int i, j, k;
	for(i=3; i<LMT; i+=2) if(!chkC(base, i)) for(j=i*i, k=i<<1; j<MAX; j+=k) setC(base, j);
	prlen=0;
	//primes[prlen++]=2;// uncomment only for segmented_sieve2
	for(i=3; i<MAX; i+=2) if(!chkC(base, i)) primes[prlen++] = i;
}

int segmented_sieve1(int a, int b) {
	int rt, i, k, cnt = (a<=2 && 2<=b)? 1 : 0;
	if(b<2) return 0;
	if(a<3) a = 3;
	if(a%2==0) a++;
	memset(segment, 0, sizeof segment);
	for(i=0, rt=(int)sqrt((double)b); i < prlen && primes[i] <= rt; i++) {
		unsigned j = primes[i] * ( (a+primes[i]-1) / primes[i] );
		if(j%2==0) j += primes[i];
		for(k=primes[i]<<1; j<=b; j+=k) if(j!=primes[i]) setC(segment, (j-a));
	}
	for(i=0; i<=b-a; i+=2) if(!chkC(segment, i)) cnt++;
	return cnt;
}
int segmented_sieve2(int a, int b) {
        for(int i=0;i<prlen;i++)
        {
            int mod = a%primes[i] ;
            int idx = primes[i] - mod ;
            if(mod==0) idx = 0 ;
            for(int j=idx;j<=b-a;j+=primes[i])
            {
                if(a+j!=primes[i])
                {
                    flag[j] = 1 ;
                }
            }
        }
        int c=0;
        for(int i=0;i<=b-a;i++)
        {
            if(flag[i]!=1 && i+a!=1)
            {
                //printf("%d ",i+a);
                c++;
            }
        }
        //printf("\n");
        return c;
}
int main() {
	int test, cs, a, b;
	sieve();
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &a, &b);
		printf("Case %d: %d\n", cs, segmented_sieve1(a, b));
	}
	return 0;
}
