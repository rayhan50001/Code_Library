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
#define   ll			    int
#define   pii			    pair<ll,ll>
#define   READ 		        freopen("input.txt", "r", stdin)
#define   WRITE 		    freopen("output.txt", "w", stdout)
#define   FOR(i,a,b) 		for(int i=a;i<=b;i++)
#define   RFOR(i,a,b) 		for(int i=a;i>=b;i--)
#define   sfll(a) 		    scanf("%d",&a)
#define   sfll2(a,b) 		scanf("%d %d",&a,&b)
#define   sfll3(a,b,c) 	    scanf("%lld%lld%lld",&a,&b,&c)
#define   cs 			    printf("Case %d: ",kk++)
#define   cn 			    printf("Case %d:\n",kk++)
#define   pfll(a) 		    printf("%d",a)
#define   nl			    printf("\n")
#define   done 		        printf("DONE\n")
#define   EPS			    1e-9
#define   MOD 			    1000000007
//#define   MAX			    1e6
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

// MAIN FUNCTION
//brute force
/*vector<ll>v;
set<ll>st1;
bitset<300000001>pr;
vector<ll>prime;
void sieve()
{
    pr[0]=pr[1]=1;
    for(int i=2; i*i<=100001; i++)
    {
        if(pr[i]==0)
        {
            for(int j=i*i; j<=100001; j+=i)
            {
                pr[j]=1;
            }
        }
    }
    for(int i=0; i<1000; i++)if(pr[i]==0)prime.push_back(i);
}
void pre()
{

    for(int i=1; i<300; i++)
    {
        for(int j=1; j<300; j++)
        {
            ll val=powl(i,2)+powl(j,2);
            if(val<=3*1e8)
            {
               if(st1.find(val)==st1.end() && pr[val]==0)
                    st1.insert(val);
            }
        }
    }
    for(auto it: st1)v.pb(it);
}
*/
//bitwise sieve for memory optimization. MEMORY = O(sqrt(MAX)) TL= MAX * long(MAX)
#define MAX 300000009//max num to prime
#define LMT (ll)sqrt(MAX)+5 //sqrt(MAX)

int isprime[MAX/64];

#define chkC(n) (isprime[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (isprime[n>>6]|=(1<<((n>>1)&31)))

void sieve()
{
    unsigned i,j,k;
    isprime[0]|=0;
    for(i=3;i<LMT;i+=2)
        if(!chkC(i))
            for(j=i*i,k=i<<1;j<MAX;j+=k)
                setC(j);
}
int main()
{
    //result = 4*k+1 is summation of two perfect square (where k arbitrary)
    sieve();
    //pre();
    //for(int i=0; i<20; i++)cout<<prime[i]<<" ";
    //cout<<endl;
    //for(int i=0; i<20; i++)cout<<v[i]<<" ";
    //cout<<endl;
    ll l,r;
    sfll2(l,r);
    int cnt=0;
    if(l<=2 && 2<=r)cnt++;
    ll st=max(l,3);
    for(int i=(st%2==0)?st+1:st; i<=r; i+=2)
    {
        if((!chkC(i) && (i-1)%4==0))cnt++;
    }
    cout<<cnt<<endl;
}
