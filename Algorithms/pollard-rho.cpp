#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"


const ll MAX = 100000000;
const ll LMT = 10000;
bool isprime[MAX];

void sieve()    //Sieve of Eratosthenes
{
    memset(isprime, true, sizeof(isprime));

    ll i, k, j;
    isprime[1] = false;
    for (i = 4; i <= MAX; i+=2)
    {
        isprime[i] = false;
    }
    for (i = 3; i <= LMT; i+=2)
    {
        if(isprime[i])
            for (j = i*i, k = i<<1; j <= MAX; j+=k)
            {
                isprime[j] = false;
            }
    }
}

ll abso(ll a)     //fn to return absolute value
{
    return a>0?a:-a;
}
ll gcd(ll a,ll b)    //Euclidean GCD recursive fn
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

ll pollard_rho(ll n)  //pollard rho implementation
{
    if(n%2==0)
        return 2;

    ll x = rand()%n+1;
    ll c = rand()%n+1;
    ll y = x;
    ll g = 1;

    //fn is f(x) = x*x + c
    while(g==1)
    {
        x = ((x*x)%n + c)%n;
        y = ((y*y)%n + c)%n;
        y = ((y*y)%n + c)%n;
        g = gcd(abso(x-y),n);
    }
    return g;
}

ll factors[MAX/100], total;

void factorize(ll n)   //fn to factorize the number
{
    if(n == 1)
        return;

    if(isprime[n])      //if n is prime,store it
    {
        factors[total++] = n;
        return;
    }
    ll divisor = pollard_rho(n);   //get a divisor of n
    factorize(divisor);
    factorize(n/divisor);
}

ll main()  //Driver Program
{
    srand(time(NULL));
    sieve();

	ll n;
    scanf("%d",&n);

    total = 0;
    factorize(n);

    for (ll i = 0; i < total; ++i)
    {
        prllf("%d ",factors[i] );
    }
    prllf("\n");
	return 0;
}
