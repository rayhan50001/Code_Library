//Bismillahir-Rahmanir-Rahim (In The Name Of ALLAH)



//everything is long long

#include<bits/stdc++.h>
//#include<unordered_map>

using namespace std;

//... Define Section

#define   mem(a,val)		memset(a,val,sizeof(a))
#define   all(a)		a.begin(),a.end()
#define   sz(A) 		A.size()
#define   len(A)		strlen(A)
#define   ff                  	first
#define   ss                  	second
#define   pb 			push_back
#define   PI			acos(-1.00)
#define   ll			long long
#define   pii			pair<ll,ll>
#define   READ 		freopen("input.txt", "r", stdin)
#define   WRITE 		freopen("output.txt", "w", stdout)
#define   FOR(i,a,b) 		for(int i=a;i<=b;i++)
#define   RFOR(i,a,b) 		for(int i=a;i>=b;i--)
#define   sfll(a) 		scanf("%lld",&a)
#define   sfll2(a,b) 		scanf("%lld%lld",&a,&b)
#define   sfll3(a,b,c) 	scanf("%lld%lld%lld",&a,&b,&c)
#define   cs 			printf("Case %d: ",kk++)
#define   cn 			printf("Case %d:\n",kk++)
#define   pfll(a) 		printf("%lld",a)
#define   nl			printf("\n")
#define   done 		printf("DONE\n")
#define   EPS			1e-9
#define   MOD 			1000000007
#define   MAX			1e6
#define   fast 		ios_base::sync_with_stdio(false);

//BitMask Section

#define   setbit(mask,i) 	mask |= (1<<i) // mask = 1010 i=2 then mask = 1110
#define   clearbit(mask,i) 	mask &= ~(1<<i) // mask = 1010 i=3 then mask = 0010
#define   checkbit(mask,i) 	mask &  (1<<i) // mask = 1010 i=3 then mask = 1000
#define   togglebit(mask,i) 	mask ^= (1<<bit)

//Default Function

template<typename T>inline string Tostring(T a){ostringstream os("");os << a;return os.str();} //number to string
template<typename T>inline ll Tolong(T a){ll res;istringstream os(a);os>>res;return res;} //string to number
template< class T > inline T Bigmod(T n,T m,T mod){T ans=1,mult=n%mod;while(m){if(m & 1) ans=(ans*mult)%mod;m>>=1;mult=(mult*mult)%mod;}ans%=mod;return ans;}//Big Mod (A^B)%M
template< class T > inline T Modinv(T x,T mod){return _bigmod(x,(T) mod-2)%mod;} // Modular Inverse (A/B=A^(-B))%M
template<typename T>inline vi Parse(T str){vi res;int s;istringstream os(str);while(os>>s)res.pb(s);return res;}//string to vector
template< class T > inline T Lcm(T x,T y){return x*y/__gcd(x,y);}//LCM (a*b)/gcd(a,b)
template<typename T> inline T pwr(T b, T p) {T res  = 1;while(p > 0) {if(p&1) {res *= b ;}b *= b;p >>= 1;}return res ;}//power a^b
template <typename T>inline vector< T > Unique(vector< T > v) {sort(v.begin(), v.end());v.erase(unique(v.begin(), v.end()),v.end());return v;}// 1 2 1 3 = 1 2 3 (vector)


//Direction Array

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

//Running Time

clock_t begin,end;
double time_spent;
#define   timestart()		begin=clock()
#define   timestop()		end=clock()
#define   calc()		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
#define   timelimit()		cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;


// MAIN FUNCTION

int main()
{
     
    return 0;
}
