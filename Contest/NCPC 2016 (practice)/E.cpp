#include <bits/stdc++.h>
using namespace std;
#define MAX                 1000010
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define fi                  first
#define se                  second
#define pi                  acos(-1)
#define sf                  scanf
#define pf                  printf
#define SIZE(a)             ((int)a.size())
#define All(S)              S.begin(), S.end()
#define Equal(a, b)         (abs(a-b) < EPS)
#define Greater(a, b)       (a >= (b+EPS))
#define GreaterEqual(a, b)  (a > (b-EPS))
#define fr(i, a, b)         for(register int i = (a); i < (int)(b); i++)
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fileRead(S)         freopen(S, "r", stdin);
#define fileWrite(S)        freopen(S, "w", stdout);
#define Unique(X)           X.erase(unique(X.begin(), X.end()), X.end())

#define isOn(S, j)          (S & (1 << j))
#define setBit(S, j)        (S |= (1 << j))
#define clearBit(S, j)      (S &= ~(1 << j))
#define toggleBit(S, j)     (S ^= (1 << j))
#define lowBit(S)           (S & (-S))
#define setAll(S, n)        (S = (1 << n) - 1)

typedef unsigned long long ull;
typedef long long ll;
typedef map<int, int> mii;
typedef map<ll, ll>mll;
typedef map<string, int> msi;
typedef vector<int> vi;
typedef vector<long long>vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pair<int, int> > vii;
typedef vector<pair<ll, ll> >vll;


//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------


ll powerMOD(ll x, ll y) {                   // Can find modular inverse by a^(MOD-2),  a and MOD must be co-prime
    ll res = 1;
    x %= MOD;
    while(y > 0) {
        if(y&1) res = (res*x)%MOD;          // If y is odd, multiply x with result
        y = y >> 1, x = (x * x)%MOD;
    }
    return res%MOD;
}


ll fa[MAX] = {0}, fainv[MAX] = {0};                 // fa and fainv must be in global
ll C(ll n, ll r) {                                  // Usable if MOD value is present
    if(fa[0] == 0) {                                // Auto initialize
        fa[0] = 1, fainv[0] = powerMOD(1, MOD-2);
        for(int i = 1; i < MAX; ++i) {
            fa[i] = (fa[i-1]*i) % MOD;              // Constant MOD
            fainv[i] = powerMOD(fa[i], MOD-2);
    }}
    //cerr << "DONE\n";
    if(n < 0 || r < 0 || n-r < 0) return 0;         // Exceptional Cases
    return ((fa[n] * fainv[r])%MOD * fainv[n-r])%MOD;
}

/*
// Combination
// Complexity O(k)
long long C(int n, int k) {
    long long c = 1;
    if(k > n - k)
        k = n-k;
    for(int i = 0; i < k; i++) {
        c *= (n-i);
        c /= (i+1);
    }
    return c;
}*/

ll NumOfSameValueInCombination(int n, int r) {          // Returns number of same value in a set of nCr combination
    if(n < r) return 0;
    n = r + abs(n-r);
    return C(n-1, r-1);
}

map<pll, ll>DP;
void pre()
{
    for(ll i=2; i<=1000000; i++)
    {
        DP[{i,i}]=1LL;
        for(ll j=i+i; j<=1000000; j+=i)
        {
            DP[{j,i}]=(DP[{j-i,i}]%MOD*NumOfSameValueInCombination(j, i)%MOD)%MOD;
        }
    }
}
//ll RET(ll N, ll K) {
//    ll ret = 1;
//    //cerr << N << " : " << K << " = ";
//    ll T = N;
//    while(N > K) {
//        if(DP.find({N, K}) != DP.end()) {
//            //cerr << "HIT\n";
//            ret *= DP[{N, K}];
//            goto SKIP;
//        }
//
//        ret *= NumOfSameValueInCombination(N, K);
//        //cerr << NumOfSameValueInCombination(N, K) << " ";
//
//        SKIP:
//        N -= K;
//        ret %= MOD;
//    }
//    //cerr << endl;
//    //cerr << "DP " << T << " " << K << " saved\n";
//    DP[{T, K}] = ret;
//    return ret;
//}


ll SOLVE(ll n) {
    ll lim = sqrt(n), sum = 0;
    if(n%2 == 0) {
        for(int i = 2; i <= lim; ++i) {
            if(n%i == 0) {
                sum += DP[{n, i}];
                sum %= MOD;
            }
            if(n/i != i) {
                sum += DP[{n, n/i}];
                sum %= MOD;
            }
        }
    }

    if(n >= 1) sum++;
    if(n > 1) sum++;
    return sum;
}

vll v;
ll ans[6000];

int main() {
    //fileRead("out");

    ll n, x;
    scanf("%lld", &n);
    v.resize(n);

    for(int i = 0; i < n; ++i) {
        scanf("%lld", &x);
        v[i].first = -x, v[i].second = i;
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < n; ++i) {
        ans[v[i].second] = SOLVE(-v[i].first);
    }

    for(int i = 0; i < n; ++i)
        printf("Case %d: %lld\n", i+1, ans[i]);
    return 0;
}
