// minimum number of straight line need cover all points. (bitmask dp)
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

ll colinear[21][21];
ll dp[1<<20];
ll x[21];
ll y[21];
bool same_straight_line(int i,int j,int k)
{
    ll same=((x[i] - x[j]) * (y[k] - y[j]) - (y[i] - y[j]) * (x[k] - x[j]));
    return same == 0;
}
ll solve(ll mask,ll n)
{
    if(mask==(1LL<<n)-1)return 0;
    if(dp[mask]!=-1)return dp[mask];
    ll bit=__builtin_popcount(mask);
    if(bit==n-1)return dp[mask]=1;
    ll ans=1e9;
    for(int i=0; i<n; i++)
    {
        if(checkBit(mask,i)==0)
        {
            for(int j=0; j<n; j++)
            {
                if(checkBit(mask,j)==0 && i!=j)
                ans=min(ans,1+solve(mask|colinear[i][j],n));
            }
            return dp[mask]=ans;
        }
    }
}
// MAIN FUNCTION
int main()
{
    ll tt,kk=1;
    sfll(tt);
    while(tt--)
    {
        ll n;
        sfll(n);
        for(int i=0; i<n; i++)
            sfll2(x[i],y[i]);
        if(n<=2)
        {
            cs;
            pfll(1);
            nl;
            continue;
        }
        mem(dp,-1);
        mem(colinear,0);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                    for(int k=0; k<n; k++)
                    {
                        if(same_straight_line(i,j,k))
                        {
                            colinear[i][j]=setBit(colinear[i][j],k);
                        }
                    }
            }
        }
//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<n; j++)
//            {
//                cout<<colinear[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        ll ans=solve(0,n);
        cs;
        pfll(ans);
        nl;
    }
    return 0;
}
