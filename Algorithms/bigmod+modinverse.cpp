
#define ll long long
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

long long int bigmod(long long  x,long long  n,long long  M)
{
long long  result=1;
while(n>0)
{
if(n % 2 ==1)
result=(result * x)%M;
x=(x*x)%M;
n=n/2;
}
return result;
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
