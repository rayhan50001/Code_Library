
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
#define   MAX			    100009
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
ll arr[MAX], dp[MAX][31], l[MAX], r[MAX], color[MAX];
int main()
{
    ll n,c;
    while(sfll2(n,c)==2 && n && c)
    {
        FOR(i,1,n)sfll(arr[i]);
        FOR(i,0,30)dp[0][i]=0;
        FOR(i,1,n)
        {
            sfll(color[i]);
            FOR(j,0,c-1)
            {
                if(j==color[i])dp[i][j]=dp[i-1][j]+1;
                else dp[i][j]=dp[i-1][j];
            }
        }
        arr[0] = arr[n+1] = 0;
        vector<int> stk;
        stk.push_back(0);
        for (int i = 1; i <= n; i++) {
            while (arr[i] <= arr[stk.back()])
                stk.pop_back();
            l[i] = stk.back() + 1, stk.push_back(i);
        }

        while (!stk.empty())	stk.pop_back();

        stk.push_back(n + 1);
        for (int i = n; i >= 1; i--) {
            while (arr[i] <= arr[stk.back()])
                stk.pop_back();
            r[i] = stk.back() - 1, stk.push_back(i);
        }
        for(int i=1; i<=n; i++)
        {
            printf("%d %d\n",l[i],r[i]);
        }
        printf("\n");
        ll ans=0;
        for(int i=1; i<=n; i++)
        {
            int hbe=1;
            for(int j=0; j<c; j++)
            {
                if((dp[r[i]][j]-dp[l[i]-1][j])==0)
                {
                    hbe=0;
                    break;
                }
            }
            if(hbe==1)
            {
            ll val=(r[i]-l[i]+1)*arr[i];
            ans=max(ans,val);
            }
        }
        pfll(ans);
        nl;
    }
}
