
#include <bits/stdc++.h>
using namespace std;
#define MAX                 15
#define EPS                 1e-9
#define INF                 0x3f3f3f3f
#define MOD                 10007
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
#define FastRead            ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

int a, b, c, len, aCnt, bCnt;

void bit(int x) {
	bitset<4>b(x);
	cerr << b << endl;
}
int dp[1<<18][20];
int recur(int pos, int k, int aa) {
	//cerr << pos << " " << k << endl;
	//bit(aa);
    //if(dp[pos][k]!=-1)return dp[pos][k];
	if(pos == len) {
		int bb = abs(aa-c);
		if(k == 0 and bb > 0 and __builtin_popcount(bb) == bCnt and aa+bb == c) {
			//cerr << "MATCH " << aa << " " << bb << endl;
			return 1;
		}
		return 0;
	}

	int ret = recur(pos+1, k, aa);
	if(k)
		ret += recur(pos+1, k-1, aa|(1<<pos));
	return ret;
}
/*
int BruteForce(int x) {
	vi v;
	while(x) {
		v.pb(x%2);
		x/=2;
	}
	sort(All(v));
	do {
		int tmp = 0;
		for(int i = 0; i < SIZE(v); ++i)
			tmp += (1<<i)*v[i];

		tmp -=
	} while(next_permutation(All(v)));
}*/

int main() {
	int t;
	sf("%d", &t);
	while(t--) {

        memset(dp,-1,sizeof dp);
		sf("%d%d%d", &a, &b, &c);
		if(a < b) swap(a, b);

		len = 0;
		int tmp = a;
		while(tmp) {
			tmp /= 2;
			++len;
		}

		++len;
		aCnt = __builtin_popcount(a);
		bCnt = __builtin_popcount(b);

		pf("%d\n", recur(0, aCnt, 0));
	}
	return 0;
}

/*

11111111111111000000000000000
536838144
sum : 1073676288

1111111111111000000000000000
268402688
sum : 536805376

1
268402688 268402688 536805376

*/
