#include <bits/stdc++.h>
using namespace std;
#define MAX                 300000
#define EPS                 1e-9
#define INF                 1e7
#define MOD                 1000000007
#define pb                  push_back
#define mp                  make_pair
#define xx                  first
#define yy                  second
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

#include <ext/pb_ds/assoc_container.hpp>    // rb_tree_tag
#include <ext/pb_ds/tree_policy.hpp>        // tree_order_statistics_node_update
#define at(X)          find_by_order(X)
#define lessThan(X)    order_of_key(X)
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
//----------------------------------------------------------------------------------------------------------



bool hand(char x) {					// 0 : left
	if(x == 'd' or x == 'f')		// 1 : right
		return 0;
	return 1;
}

map<string, int>MAP;

int main() {
	int n, t;
	string str;

	cin >> t;
	while(t--) {
		cin >> n;
		MAP.clear();
		int tot = 0;

		while(n--) {
			cin >> str;
			if(MAP.find(str) != MAP.end()) {
				tot += MAP[str]/2;
				continue;
			}

			int t = 0;
			for(int i = 0; i < SIZE(str); ++i) {
				if(i != 0) {
					if(hand(str[i-1]) == hand(str[i]))
						t += 4;
					else
						t += 2;
				}
				else
					t += 2;
				//cerr << str[i] << " " << t << endl;
			}

			MAP[str] = t;
			//cerr << str << " " << t << endl;
			tot += t;
		}

		cout << tot << endl;
	}
	return 0;
}
