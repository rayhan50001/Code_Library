#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int pr[10000001];
vector<ll>prime;
#define for0(i,a) for(int i=0;i<a;i++)
#define pb push_back
#define mp make_pair
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
int main()
{
    Factor::init(200000);
    int tt;
    cin>>tt;
    while(tt--)
    {
        ll a,b,n;
        cin>>a>>b>>n;
        vector<pair<ll,ll> >a1=Factor::factorG(a);
        vector<pair<ll,ll> >b1=Factor::factorG(b);
        if(abs(a-b)==0)
        {
            ll ans=(2*bigMod(a,n,mod)%mod)%mod;
            if(ans<0)ans+=mod;
            cout<<ans<<endl;
            continue;
        }
        vector<pair<ll,ll> >ab=Factor::factorG(abs(a-b));
        map<ll,ll>check;
        map<ll,ll>common;
        map<ll,ll>in1;
        map<ll,ll>in2;
        map<ll,ll>ans;
        for(int i=0; i<a1.size(); i++)
        {
            a1[i].second=a1[i].second*n;
            check[a1[i].first]=a1[i].second;
        }
        for(int i=0; i<b1.size(); i++)
        {
            b1[i].second=b1[i].second*n;
            if(check[b1[i].first])
            {
                common[b1[i].first]=min(b1[i].second,check[b1[i].first]);
            }
        }
        for(int i=0; i<a1.size(); i++)
        {
            if(common[a1[i].first])
            {
                in1[a1[i].first]=max(0LL,a1[i].second-common[a1[i].first]);
            }
            else
            {
                in1[a1[i].first]=a1[i].second;
            }
        }
        for(int i=0; i<b1.size(); i++)
        {
            if(common[b1[i].first])
            {
                in2[b1[i].first]=max(0LL,b1[i].second-common[b1[i].first]);
            }
            else
            {
                in2[b1[i].first]=b1[i].second;
            }
        }
        for(int i=0; i<ab.size(); i++)
        {
            if(common[ab[i].first])
            {
                ans[ab[i].first]=min(ab[i].second,common[ab[i].first]);
            }
            ll sum1=1,sum2=1;
            for(auto it:in1)
            {
                sum1=(sum1%ab[i].first*bigMod(it.first,it.second,ab[i].first)%ab[i].first)%ab[i].first;
            }
            for(auto it:in2)
            {
                sum2=(sum2%ab[i].first*bigMod(it.first,it.second,ab[i].first)%ab[i].first)%ab[i].first;
            }
            if((sum1+sum2)%ab[i].first==0)
            {
                ans[ab[i].first]=min(ab[i].second,ans[ab[i].first]+1);
            }
        }
        ll res=1;
        for(auto it:ans)
        {
            res=res*bigMod(it.first,it.second,mod);
            res%=mod;
        }
        if(res<0)res+=mod;
        cout<<res<<endl;
    }
}
