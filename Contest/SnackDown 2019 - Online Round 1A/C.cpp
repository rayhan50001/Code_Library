
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
// start coding
inline void fastIn(int &num)            // Fast IO, with space and new line ignoring
{
    bool neg = false;
    register int c;
    num = 0;
    c = getchar();
    for( ; c != '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-')
    {
        neg = true;
        c = getchar();
    }
    for(; (c>47 && c<58); c=getchar())
        num = (num<<1) + (num<<3) + c - 48;
    if(neg)
        num *= -1;
}
int arr[10001];
int gcd[51][51];
int par[10001];
vector<int>v[10001];
void gcdd()
{
    for(int i=1; i<=51; i++)
    {
        for(int j=1; j<=51; j++)
        {
            gcd[i][j]=__gcd(i,j);
        }
    }
}
int Find(int x)
{
    if(x==par[x])return x;
    return par[x]=Find(par[x]);
}
void Union(int x,int y)
{
    int xx=Find(x);
    int yy=Find(y);
    if(xx!=yy)
    {
        par[xx] = yy;
    }
}
int brr[10001];
int vis[10001];
void dfs(int u)
{
    for(int i=0; i<v[u].size(); i++)
    {
        int nx=v[u][i];
        if(vis[nx]==0)
        {
            vis[nx]=1;
            dfs(nx);
        }
    }
}
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    gcdd();
    int tt;
    int kk=1;
    fastIn(tt);
    while(tt--)
    {
        int n;
        fastIn(n);
        for(int i=0; i<=n; i++)par[i]=i;
        for(int i=1; i<=n; i++)
        {
            fastIn(arr[i]);
            brr[i]=arr[i];
        }
        if(n==1)
        {
            cout<<0<<endl;
            cout<<arr[1]<<endl;
            continue;
        }
        ll c=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(i!=j)
                {
                    if(gcd[arr[i]][arr[j]]==1 && i!=j)
                    {
                        v[i].pb(j);
                        v[j].pb(i);
                    }
                }
            }
        }
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                dfs(i);
            }
        }
        c=0;
        int j=14;
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                c++;
                if(arr[i]==prime[j])j--;
                arr[i]=prime[j];
                j--;
                break;
            }
        }
        cout<<c<<endl;
        for(int i=1; i<=n; i++)
        {
            cout<<arr[i]<<" ";
            v[i].clear();
            vis[i]=0;
        }
        cout<<endl;
    }
}

/*

*/
