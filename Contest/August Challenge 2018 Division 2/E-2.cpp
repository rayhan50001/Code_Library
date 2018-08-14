#include<iostream>
#include<cstdio>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>
#include<deque>
#include<iterator>
#include<assert.h>
#include<bitset>
#include<climits>
#include<ctime>
#include<complex>
#include<bits/stdc++.h>
//#include<unordered_map>
using namespace std;
//define for shortcut
#define mem(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define sz(A) A.size()
#define clr(a) memset(a,0,sizeof(a))
#define pb push_back
#define pi acos(-1.0)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define vpii vector< pair<int,int> >
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define vs vector<string>
#define vi vector<int>
#define vc vector<char>
#define sts set<string>
#define sti set<int>
#define stc set<char>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
//#define ull unsigned long long
#define ll long long
#define for1(i,a,b) for(int i=a;i<=b;i++)
#define rfor1(i,a,b) for(int i=a;i>=b;i--)
#define rfor0(i,a,b) for(int i=a-1;i>b;i--)
#define for0(i,a) for(int i=0;i<a;i++)
//read input
#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sfll(a) scanf("%lld",&a)
#define sfll2(a,b) scanf("%lld%lld",&a,&b)
#define sfll3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define ss(a) scanf("%s",&a)
#define sc(a) scanf("%c",&a)
#define sd(a) scanf("%lf",&a)
#define pf(a) printf("%d",a)
#define pfll(a) printf("%lld",a)
#define pfd(a) printf("%.17f",a)
#define pc(a) printf("%c",a)
#define ps(a) printf("%s",a)
#define cs printf("Case %d: ",kk++)
#define cn printf("Case %d:\n",kk++)
///#define c# printf("Case #%d: ",kk++)
#define Mid(l,r) (l+(r-l)>>1)
#define nl printf("\n")
#define done cout<<"done"<<endl;
#define eps 1e-9
#define mod 1000000007
#define inf INT_MAX
#define MX 100010
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define fast ios_base::sync_with_stdio(false);
#define MAX 200001
inline void fastIn(ll &num) {          // Fast IO, with space and new line ignoring
    bool neg = false;
    register int c;
    num = 0;
    c = getchar();
    for( ; c != '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for(; (c>47 && c<58); c=getchar())
        num = (num<<1) + (num<<3) + c - 48;
    if(neg)
        num *= -1;
}

ll tree[4*100001];
void build(ll idx,ll l,ll r)
{
    if(l==r)
    {
        tree[idx]=0;
        return;
    }
    ll lft=2*idx;
    ll rgt=2*idx+1;
    ll mid=(l+r)/2;
    build(lft,l,mid);
    build(rgt,mid+1,r);
    tree[idx]=max(tree[lft],tree[rgt]);
}
void update(ll idx,ll l,ll r,ll pos,ll val)
{
    if(l==pos && r==pos)
    {
        tree[idx]=val;
        return;
    }
    ll lft=2*idx;
    ll rgt=2*idx+1;
    ll mid=(l+r)/2;
    if(pos<=mid)
    {
        update(lft,l,mid,pos,val);
    }
    else
    {
        update(rgt,mid+1,r,pos,val);
    }
    //tree[idx]=min(tree[lft],tree[rgt]);
    tree[idx]=max(tree[lft],tree[rgt]);
}
ll Query(ll idx,ll l,ll r,ll s,ll e)
{
    if(l==s && r==e)
    {
        return tree[idx];
    }
    ll lft=2*idx;
    ll rgt=2*idx+1;
    ll mid=(l+r)/2;
    if(e<=mid)
    {
        Query(lft,l,mid,s,e);
    }
    else if(s>mid)
    {
        Query(rgt,mid+1,r,s,e);
    }
    else
    {
        ll q1=Query(lft,l,mid,s,mid);
        ll q2=Query(rgt,mid+1,r,mid+1,e);
        //return min(q1,q2);
        return max(q1,q2);
    }
}
ll a[MAX];
ll par[MAX];
ll assign[MAX];
map<ll, vector<ll> >mp;
ll sum;

void Find(ll p1) {
	if(par[p1] == -1) return;
	ll p2 = par[p1];
	if(assign[p1] != assign[p2]) {
		sum -= assign[p2];
		sum += assign[p1];
		assign[p2] = assign[p1];
		Find(p2);
	}
}

ll simulate(ll k, ll n) {
	sum = 0;
	build(1, 1, n);
	memset(par, -1, sizeof par);
	memset(assign,0,sizeof assign);
	for(auto vv : mp) {
		vector<ll> v = vv.second;
		for(int i = 0; i < (int)v.size(); ++i) {
			bool range_ase = 0;
			if(i)
            {
				ll pstR = min((ll)n, v[i-1]+k);
				if(pstR >= v[i])
                {
					range_ase = 1;
					par[v[i]] = v[i-1];
				}
			}
			ll l=max(1LL,v[i]-k);
			ll r=min((ll)n,v[i]+k);
			ll val = Query(1,1,n,l,r);
			if(range_ase)
				val = max(val+1LL,assign[v[i-1]]);
			else
				val++;
			assign[v[i]] = val;
			sum += val;
			Find(v[i]);
		}
		for(int i = 0; i < (int)v.size(); ++i)
			update(1, 1, n, v[i], assign[v[i]]);
	}
	return sum;
}

int main() {
	ll s, n, t;
    sfll(t);
	while(t--) {
		sfll2(n,s);
		mp.clear();
		for(int i = 1; i <= n; ++i) {
			sfll(a[i]);
			mp[a[i]].pb(i);
		}
		int ans=0;
		if(s<n)ans=0;
		else{
		int lo = 1, hi = n;
		while(lo <= hi) {
			int mid = (lo+hi)>>1;
			if(simulate(mid, n) <= s) {
				ans = mid;
				lo = mid+1;
			}
			else
				hi = mid-1;
		}
        if(n<=s)ans++;
		}
        pf(ans);
        printf("\n");
	}
	return 0;
}
