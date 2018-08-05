#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
void ext_gcd ( long long A, long long B, long long *X, long long *Y ){
    long long x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
//    return r2;
}
long long modInv ( long long a, long long m ) {

    ///ll x = bigmod( a, m - 2, m );    m is a prime       ///(ax)%m = 1

    long long x, y;
    ext_gcd( a, m, &x, &y );

    ///Process x so that it is between 0 and m-1
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}
ll addMod(ll a, ll b, ll m)
{
    if (a + b < 0)
        return (a - m) + b;
    else if (a + b >= m)
        return a + b - m;
    else
        return a + b;
}
ll multiplyMod(ll a, ll b, ll m)
{
    if (b == 0 || a <=LLONG_MAX / b)
        return (a * b) % m;
    ll result = 0;
    if (a > b) swap(a,b);
    while (a > 0)
    {
        if ((a & 1) != 0)
        {
            result = addMod(result, b, m);
        }
        a >>= 1;
        b -= m - b;
        if (b < 0)
            b += m;
    }
    return result;
}
ll bigMod(ll b,ll p,ll m)
{
    ll x=1,y=b%m;
   while(p>0)
   {
       if(p%2==1)
       {
           x=multiplyMod(x,y,m);
       }
       y=multiplyMod(y,y,m);
       p=p/2LL;
   }
   return x;
}
ll fact[1000001];
void pre()
{
    fact[0]=1;
    for(ll i=1; i<=1000000; i++)
    {
     fact[i]=(fact[i-1]%MOD*i%MOD)%MOD;
    }
}
ll Multinomial(ll n,ll r)
{
    ll div=n/r;
    ll up=fact[n];
    ll niche=(fact[div]%MOD*bigMod(fact[r],div,MOD)%MOD)%MOD;
    niche=modInv(niche,MOD);
    up=up*niche;
    up%=MOD;
    return up;
}
int main()
{
    pre();
    //freopen("out.txt","w",stdout);
    int tt,kk=1;
    scanf("%d",&tt);
    while(tt--)
    {
        ll n;
        scanf("%lld",&n);
        ll sum=0;
        for(int i=1; i*i<=n; i++)
        {
            if(n%i==0)
            {
                ll res=Multinomial(n,i);
                sum+=res;
                sum%=MOD;
                if(i!=n/i)
                {
                 res=Multinomial(n,n/i);
                 sum+=res;
                 sum%=MOD;
                }
            }
        }
        printf("Case %d: %lld\n",kk++,sum);
    }
}

