//                            ببِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
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
using namespace std;
//define for shortcut
#define fi first
#define se second
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
//#define c# printf("Case #%d: ",kk++)
#define nl printf("\n")
#define done cout<<"done"<<endl;
#define eps 1e-9
#define mod 1000000007
#define inf INT_MAX
#define MX 100010
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define fast ios_base::sync_with_stdio(false);
template<typename T>inline string tostring(T a){ostringstream os("");os << a;return os.str();}
template<typename T>inline ll tolong(T a){ll res;istringstream os(a);os>>res;return res;}
template<typename T>inline vi parse(T str){vi res;int s;istringstream os(str);while(os>>s)res.pb(s);return res;}
template< class T > inline T _sqrt(T x) { return (T) sqrt( (double) x); }
template< class T > inline T _bigmod(T n,T m) {T ans=1,mult=n%mod; while(m){ if(m & 1) ans=(ans*mult)%mod; m>>=1; mult=(mult*mult)%mod; } ans%=mod; return ans;}
template< class T > inline T _modinv(T x) {return _bigmod(x,(T) mod-2)%mod;}
inline int len(string a) {return a.length();}
inline int len(char a[]) {return strlen(a);}
template<class T> inline T _gcd(T a, T b){return (b==0) ? a : _gcd(b, a % b);}
template< class T > inline T _lcm(T x,T y) { return x*y/_gcd(x,y);}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
//bool compare(const pair<float,string>&i, const pair<float,string>&j)
//{
//    return i.first > j.first;
//}
//int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
//int EQ(double d) {
//    if ( fabs(d) < EPS ) return 0;
//    return d > EPS ? 1 : -1 ;
//}
namespace Factor {
	const int N=2010000;
	ll C,fac[10010],n,mut,a[1001000];
	int T,cnt,i,l,prime[N],p[N],psize,_cnt;
	ll _e[100],_pr[100];
	vector<ll> d;
	inline ll mul(ll a,ll b,ll p) {
		if (p<=1000000000) return a*b%p;
		else if (p<=1000000000000ll) return (((a*(b>>20)%p)<<20)+(a*(b&((1<<20)-1))))%p;
		else {
			ll d=(ll)floor(a*(long double)b/p+0.5);
			ll ret=(a*b-d*p)%p;
			if (ret<0) ret+=p;
			return ret;
		}
	}
	void prime_table(){
		int i,j,tot,t1;
		for (i=1;i<=psize;i++) p[i]=i;
		for (i=2,tot=0;i<=psize;i++){
			if (p[i]==i) prime[++tot]=i;
			for (j=1;j<=tot && (t1=prime[j]*i)<=psize;j++){
				p[t1]=prime[j];
				if (i%prime[j]==0) break;
			}
		}
	}
	void init(int ps) {
		psize=ps;
		prime_table();
	}
	ll powl(ll a,ll n,ll p) {
		ll ans=1;
		for (;n;n>>=1) {
			if (n&1) ans=mul(ans,a,p);
			a=mul(a,a,p);
		}
		return ans;
	}
	bool witness(ll a,ll n) {
		int t=0;
		ll u=n-1;
		for (;~u&1;u>>=1) t++;
		ll x=powl(a,u,n),_x=0;
		for (;t;t--) {
			_x=mul(x,x,n);
			if (_x==1 && x!=1 && x!=n-1) return 1;
			x=_x;
		}
		return _x!=1;
	}
	bool miller(ll n) {
		if (n<2) return 0;
		if (n<=psize) return p[n]==n;
		if (~n&1) return 0;
		for (int j=0;j<=7;j++) if (witness(rand()%(n-1)+1,n)) return 0;
		return 1;
	}
	ll gcd(ll a,ll b) {
		ll ret=1;
		while (a!=0) {
			if ((~a&1) && (~b&1)) ret<<=1,a>>=1,b>>=1;
			else if (~a&1) a>>=1; else if (~b&1) b>>=1;
			else {
				if (a<b) swap(a,b);
				a-=b;
			}
		}
		return ret*b;
	}
	ll rho(ll n) {
		for (;;) {
			ll X=rand()%n,Y,Z,T=1,*lY=a,*lX=lY;
			int tmp=20;
			C=rand()%10+3;
			X=mul(X,X,n)+C;*(lY++)=X;lX++;
			Y=mul(X,X,n)+C;*(lY++)=Y;
			for(;X!=Y;) {
				ll t=X-Y+n;
				Z=mul(T,t,n);
				if(Z==0) return gcd(T,n);
				tmp--;
				if (tmp==0) {
					tmp=20;
					Z=gcd(Z,n);
					if (Z!=1 && Z!=n) return Z;
				}
				T=Z;
				Y=*(lY++)=mul(Y,Y,n)+C;
				Y=*(lY++)=mul(Y,Y,n)+C;
				X=*(lX++);
			}
		}
	}
	void _factor(ll n) {
		for (int i=0;i<cnt;i++) {
			if (n%fac[i]==0) n/=fac[i],fac[cnt++]=fac[i];}
		if (n<=psize) {
			for (;n!=1;n/=p[n]) fac[cnt++]=p[n];
			return;
		}
		if (miller(n)) fac[cnt++]=n;
		else {
			ll x=rho(n);
			_factor(x);_factor(n/x);
		}
	}
	void dfs(ll x,int dep) {
		if (dep==_cnt) d.pb(x);
		else {
			dfs(x,dep+1);
			for (int i=1;i<=_e[dep];i++) dfs(x*=_pr[dep],dep+1);
		}
	}
	void norm() {
		sort(fac,fac+cnt);
		_cnt=0;
		for0(i,cnt) if (i==0||fac[i]!=fac[i-1]) _pr[_cnt]=fac[i],_e[_cnt++]=1;
			else _e[_cnt-1]++;
	}
	vector<ll> getd() {
		d.clear();
		dfs(1,0);
		return d;
	}
	vector<ll> factor(ll n) {
		cnt=0;
		_factor(n);
		norm();
		return getd();
	}
	vector<pair<ll,ll> > factorG(ll n) {
		cnt=0;
		_factor(n);
		norm();
		vector<pair<ll,ll> > d;
		for0(i,_cnt) d.pb(mp(_pr[i],_e[i]));
		return d;
	}
	bool is_primitive(ll a,ll p) {
		assert(miller(p));
		vector<pair<ll,ll> > D=factorG(p-1);
		for0(i,D.size()) if (powl(a,(p-1)/D[i].first,p)==1) return 0;
		return 1;
	}
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
pair<ll,ll> no_divisor(vector<pair<ll,ll> >mp)
{
     ll ans=1;
     ll sq_sum=1;
      for(auto it:mp)
       {
            ll p=it.first;
            ll c=it.second;
            ans=multiplyMod(ans,(c+1),mod);
            ll upper=bigMod(p,(c+1)*2LL,mod);
            upper--;
            ll lower=bigMod(p,2LL,mod);
            lower--;
            ll inv_lower=modInv(lower,mod);
            ll total=(upper*inv_lower)%mod;
            sq_sum=(sq_sum*total)%mod;
       }
       return {ans,sq_sum};
}
int main()
{
     clock_t begin = clock();
    //your code goes here
    Factor::init(2000006);
    int tt,kk=1;
    sf(tt);
    while(tt--)
    {

     ll n,s;
     sfll2(n,s);
     cs;
     if((s-n)==1)
     {
        ll ans=1;
        ans+=bigMod(n,2LL,mod);
        ans%=mod;
        if(ans<0)ans+=mod;
        pfll(2LL);
        printf(" ");
        pfll(ans);
        nl;
     }
     else
     {
        vector<pair<ll,ll> >fac=Factor::factorG(n);
        pair<ll,ll>ans=no_divisor(fac);
        ll sq_sum=ans.se;
        ll divisor=ans.fi;
        pfll(divisor);
        printf(" ");
        pfll(sq_sum);
        nl;
     }
    }
   //end here
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;
    return 0;
}

