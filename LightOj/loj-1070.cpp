// a^n+b^n=(a^n-1+a^n-1)(a+b)-ab(a^n-2+a^n-2)
// f(n) = (a+b)*f(n-1)+ab*f(n-2)

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
#define   ll			    unsigned long long
#define   pii			    pair<ll,ll>
#define   READ 		        freopen("input.txt", "r", stdin)
#define   WRITE 		    freopen("output.txt", "w", stdout)
#define   FOR(i,a,b) 		for(ll i=a;i<=b;i++)
#define   RFOR(i,a,b) 		for(ll i=a;i>=b;i--)
#define   sfll(a) 		    scanf("%llu",&a)
#define   sfll2(a,b) 		scanf("%lld %lld",&a,&b)
#define   sfll3(a,b,c) 	    scanf("%llu %llu %llu",&a,&b,&c)
#define   cs 			    printf("Case %llu: ",kk++)
#define   cn 			    printf("Case %lld:\n",kk++)
#define   pfll(a) 		    printf("%llu",a)
#define   nl			    printf("\n")
#define   done 		        printf("DONE\n")
#define   EPS			    1e-9
//#define   MOD 			    1000000007
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
template<typename T>inline vector<ll> Parse(T str){vector<ll> res;ll s;istringstream os(str);while(os>>s)res.pb(s);return res;}//string to vector
template< class T > inline T Lcm(T x,T y){return x*y/__gcd(x,y);}//LCM (a*b)/gcd(a,b)
template<typename T> inline T pwr(T b, T p) {T res  = 1;while(p > 0) {if(p&1) {res *= b ;}b *= b;p >>= 1;}return res ;}//power a^b
template <typename T>inline vector< T > Unique(vector< T > v) {sort(v.begin(), v.end());v.erase(unique(v.begin(), v.end()),v.end());return v;}// 1 2 1 3 = 1 2 3 (vector)


//Direction Array

//ll dx[]={1,0,-1,0};ll dy[]={0,1,0,-1}; //4 Direction
//ll dx[]={1,1,0,-1,-1,-1,0,1};ll dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//ll dx[]={2,1,-1,-2,-2,-1,1,2};ll dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

//Running Time

clock_t begn,ed;
double time_spent;
#define   timestart()		begn=clock()
#define   timestop()		ed=clock()
void      timelimit()		{time_spent = (double)(ed - begn) / CLOCKS_PER_SEC;cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;}
// start coding
struct matrix {
    ll mat[3][3];
    matrix() { memset(mat, 0, sizeof(mat)); }
};
matrix mul(matrix a, matrix b, ll p, ll q, ll r) {		// O(n^3) :: r1, c1, c2  [c1 = r2]
    matrix ans;
    for(ll i = 0; i < p; ++i)
        for(ll j = 0; j < r; ++j) {
            ans.mat[i][j] = 0;
            for(ll k = 0; k < q; ++k)
                ans.mat[i][j] = (ans.mat[i][j] + (a.mat[i][k] * b.mat[k][j]));
        }
    return ans;
}
matrix matPow(matrix base, ll p, ll s) {               // O(logN), s : size of square matrix
    if(p == 1) return base;
    if(p & 1)  return mul(base, matPow(base, p-1, s), s, s, s);
    matrix tmp = matPow(base, p/2, s);
    return mul(tmp, tmp, s, s, s);
}
int main()
{
    ll tt,kk=1;
    sfll(tt);
    while(tt--)
    {
        ll x,y,n;
        cin>>x>>y>>n;
        cs;
        matrix mat;
        mat.mat[0][0]=x;
        mat.mat[0][1]=-y;
        mat.mat[1][0]=1;
        ll  xx=((x*x)-2*y);
        if(n == 0)
        {
            cout<<2<<endl;
            continue;
        }
        if(n == 1)
        {
            cout<<x<<endl;
            continue;
        }
        if(n == 2)
        {
            cout<<xx<<endl;
            continue;
        }
        matrix ans=matPow(mat,n-2,2);
        ll res=ans.mat[0][0]*xx+ans.mat[0][1]*x;
        pfll(res);
        nl;
    }
}

