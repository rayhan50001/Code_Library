
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
ll TREE[4*100001];
ll arr[1000001];


void build(int node,int l,int r)
{
    if(l==r)
    {
        TREE[node]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    int lft=node*2;
    int rgt=lft+1;
    build(lft,l,mid);
    build(rgt,mid+1,r);
    TREE[node]= Lcm(TREE[lft],TREE[rgt]);
}
ll query(int node, int l, int r, int L,int R)
{
    if(r<L || R<l)return -1;
    if(L<=l && r<=R)
    {
        return TREE[node];
    }
    int mid=(l+r)/2;
    int lft=node*2;
    int rgt=lft+1;
    ll p1=query(lft,l,mid,L,R);
    ll p2=query(rgt,mid+1,r,L,R);
    if(p1==-1)return p2;
    if(p2==-1)return p1;
    return Lcm(p1,p2);
}
bool check(ll mid,int n)
{
    for(int i=mid; i<=n; i++)
    {
        int l=mid-i+1;
        int r=i;
        if(query(1,1,n,l,r)==1)return 1;
    }
    return 0;
}
int main()
{
    ll tt;
    sfll(tt);
    while(tt--)
    {
        ll n;
        sfll(n);
        memset(TREE,0,sizeof TREE);
        for(int i=1; i<=n; i++)
        {
            sfll(arr[i]);
        }
        build(1,1,n);
        ll l=2;
        ll r=n;
        ll ans=-1;
        while(l<=h)
        {
            ll mid=(l+r)/2;
            if(check(mid,n))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        pfll(ans);
        nl;
    }
}

