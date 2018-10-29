
//Bismillahir-Rahmanir-Rahim (In The Name Of ALLAH)

//everything is long long

#include<bits/stdc++.h>
//#include<unordered_map>

using namespace std;

//... Define Section

#define   mem(a,val)		memset(a,val,sizeof(a))
#define   all(a)		    a.begin(),a.end()
#define   sz(A) 		    A.size()
#define   len(A)		    strlen(A)
#define   ff                first
#define   ss                second
#define   pb 			    push_back
#define   PI			    acos(-1.00)
#define   ll			    long long
#define   pii			    pair<ll,ll>
#define   READ 		        freopen("input.txt", "r", stdin)
#define   WRITE 		    freopen("output.txt", "w", stdout)
#define   FOR(i,a,b) 		for(int i=a;i<=b;i++)
#define   RFOR(i,a,b) 		for(int i=a;i>=b;i--)
#define   sfll(a) 		    scanf("%lld",&a)
#define   sfll2(a,b) 		scanf("%lld %lld",&a,&b)
#define   sfll3(a,b,c) 	    scanf("%lld%lld%lld",&a,&b,&c)
#define   cs 			    printf("Case %lld: ",kk++)
#define   cn 			    printf("Case %lld:\n",kk++)
#define   pfll(a) 		    printf("%lld",a)
#define   nl			    printf("\n")
#define   done 		        printf("DONE\n")
#define   EPS			    1e-9
#define   MOD 			    1000000007
#define   MAX			    1e6
#define   fast 		        ios_base::sync_with_stdio(false);

//BitMask Section

#define   checkBit(S, j)    (S & (1 << j))
#define   setBit(S, j)      (S |= (1 << j))
#define   clearBit(S, j)    (S &= ~(1 << j))
#define   toggleBit(S, j)   (S ^= (1 << j))
#define   lowBit(S)         (S & (-S))
#define   setAll(S, n)      (S = (1 << n) - 1)
//Default Function

template<typename T>inline string Tostring(T a){ostringstream os("");os << a;return os.str();} //number to string
template<typename T>inline ll Tolong(T a){ll res;istringstream os(a);os>>res;return res;} //string to number
template< class T > inline T Bigmod(T n,T m,T mod){T ans=1,mult=n%mod;while(m){if(m & 1) ans=(ans*mult)%mod;m>>=1;mult=(mult*mult)%mod;}ans%=mod;return ans;}//Big Mod (A^B)%M
template< class T > inline T Modinv(T x,T mod){return _bigmod(x,(T) mod-2)%mod;} // Modular Inverse (A/B=A^(-B))%M
template<typename T>inline vector<int> Parse(T str){vector<int> res;int s;istringstream os(str);while(os>>s)res.pb(s);return res;}//string to vector
template< class T > inline T Lcm(T x,T y){return x*y/__gcd(x,y);}//LCM (a*b)/gcd(a,b)
template<typename T> inline T pwr(T b, T p) {T res  = 1;while(p > 0) {if(p&1) {res *= b ;}b *= b;p >>= 1;}return res ;}//power a^b
template <typename T>inline vector< T > Unique(vector< T > v) {sort(v.begin(), v.end());v.erase(unique(v.begin(), v.end()),v.end());return v;}// 1 2 1 3 = 1 2 3 (vector)


//Direction Array

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

//Running Time

clock_t begn,ed;
double time_spent;
#define   timestart()		begn=clock()
#define   timestop()		ed=clock()
void      timelimit()		{time_spent = (double)(ed - begn) / CLOCKS_PER_SEC;cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;}
// start coding
struct circle
{
    double x, y, r;
}arr[100001];
//double dist1(node x1,node x2)
//{
//    return (sqrt(powl((x1.x-x2.x),2)+powl((x1.y-x2.y),2))+(x1.r+x2.r));
//}
//double dist2(node x1,node x2)
//{
//    return (sqrt(powl((x1.x-x2.x),2)+powl((x1.y-x2.y),2))-(x1.r+x2.r));
//}
double dist(circle p1, circle p2) {
	ll x = p1.x-p2.x;
	ll y = p1.y-p2.y;
	return sqrt(x*x + y*y);
}

// What if the circles intersect ??
pair<double,double> DistRange(circle a, circle b) {
	pair<double,double> ret;
	if(a.r < b.r) swap(a, b);
	double d = dist(a, b);
	// a.r > b.r
	// a & b doesn't coincide (touches or not touches)
	if(d >= a.r+b.r)
		ret.first = max(d-a.r-b.r, 0.0), ret.second = d+a.r+b.r;
	else {		// a & b coincides (touches or not touches)
		if(d == a.r-b.r)			// a & b touches
			ret.first = 0;
		else						// a & b not touches
			ret.first = a.r-d-b.r;
		ret.second = a.r+d+b.r;		// a & b touch or not touch max is same?
	}
	return ret;
}
int main()
{
    ll n,q;
    sfll2(n,q);
    for(int i=0; i<n; i++)
    {
        double x,y,r;
        cin>>x>>y>>r;
        arr[i].x=x;
        arr[i].y=y;
        arr[i].r=r;
    }
    vector<double>mx;
    vector<double>mn;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
           pair<double,double>distan=DistRange(arr[i],arr[j]);//first=min and second=max
           mx.pb(distan.second);
           mn.pb(distan.first);
        }
    }
//    mx.pb(1.35);
//    mn.pb(1.85);
    sort(mx.begin(),mx.end());
    sort(mn.begin(),mn.end());
//    cout<<endl;
//    for(int i=0; i<mx.size(); i++)cout<<mn[i]<<" "<<mx[i]<<endl;
//    cout<<endl;
//    int len=(n*(n-1))/2;
    for(int i=0; i<q; i++)
    {
        double k;
        cin>>k;
        ll low1 = upper_bound(mn.begin(),mn.end(),k)-mn.begin();
        ll low2 = lower_bound(mx.begin(),mx.end(),k)-mx.begin();
        cout<<abs(low1-low2)<<endl;
    }
}
