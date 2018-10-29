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
ll fact[1000001];
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
void factorial()
{
    fact[0]=1;
    for(int i=1; i<=1000001; i++)
    {
        fact[i]=(fact[i-1]%MOD*i%MOD)%MOD;
        if(fact[i]<0)fact[i]+=MOD;
    }
}
ll possible(ll occur1)
{
    ll half1=(occur1)/2;
    //cout<<half1<<" ";
    ll up1=fact[occur1]%MOD;
    if(up1<0)up1+=MOD;

    ll lower1=bigMod(2LL,half1,MOD);
    if(lower1<0)lower1+=MOD;

    ll lower2=fact[half1]%MOD;
    if(lower2<0)lower2+=MOD;

    ll lower=(lower1%MOD*lower2%MOD)%MOD;
    if(lower<0)lower+=MOD;

    ll low1=modInv(lower,MOD)%MOD;
    if(low1<0)low1+=MOD;

    ll res1=(up1%MOD*low1%MOD)%MOD;
    if(res1<0)res1+=MOD;

    return res1;
}
int main()
{
    factorial();
    ll tt;
    sfll(tt);
    while(tt--)//formula: ( N!/(2^(N/2)*(N/2)!) )
    {
        ll ans=1;
        map<ll,ll>mp;
        vector<ll>v;
        ll n;
        sfll(n);
        FOR(i,1,n)
        {
            ll x;
            sfll(x);
            if(!mp[x])v.pb(x);
            mp[x]++;
        }
        sort(v.begin(),v.end());
        if(v.size()>=1)
        {
            ans=(possible(mp[v[v.size()-1]]))%MOD;
            if(mp[v[v.size()-1]]%2==0)mp[v[v.size()-1]]=0;
            else mp[v[v.size()-1]]=1;
        }
        //cout<<v.size()<<endl;
        //cout<<ans<<endl;
        RFOR(i,v.size()-2,0)
        {
            if(mp[v[i]]%2==0 and mp[v[i+1]]%2==1 and i+1<v.size())
            {
                //cout<<mp[v[i]]<<" "<<mp[v[i+1]]<<" ";
                ll occur1=mp[v[i]];
                ll mul=occur1;
                occur1--;
                ans=(ans%MOD*(possible(occur1)%MOD))%MOD;
                ans=(ans%MOD*mul%MOD)%MOD;// 3 3 4 because 4 can choose 3 = 2 time multiply by frequency of 3.
                if(ans<0)ans+=MOD;

                mp[v[i+1]]=0;
                mp[v[i]]=1;
            }
            else if(mp[v[i]]%2==1 and mp[v[i+1]]%2==0 and i+1<v.size())
            {
                //cout<<mp[v[i]]<<" "<<mp[v[i+1]]<<" ";
                ll occur1=mp[v[i]];
                ans=(ans%MOD*(possible(occur1)%MOD))%MOD;
                if(ans<0)ans+=MOD;

                mp[v[i+1]]=0;
                mp[v[i]]=1;

            }
            else if(mp[v[i]]%2==1 and mp[v[i+1]]%2==1 and i+1<v.size())
            {
                //cout<<mp[v[i]]<<" "<<mp[v[i+1]]<<" ";
                ll occur1=mp[v[i]]+mp[v[i+1]];
                ans=(ans%MOD*possible(occur1)%MOD)%MOD;
                if(ans<0)ans+=MOD;

                mp[v[i+1]]=0;
                mp[v[i]]=0;
            }
            else
            {
                //cout<<mp[v[i]]<<" "<<mp[v[i+1]]<<endl;
                ll occur1=mp[v[i]]+mp[v[i+1]];
                ans=(ans%MOD*possible(occur1)%MOD)%MOD;
                if(ans<0)ans+=MOD;
                mp[v[i+1]]=0;
                mp[v[i]]=0;
            }
        }
        if(ans<0)ans+=MOD;
        pfll(ans);
        nl;
    }
}
