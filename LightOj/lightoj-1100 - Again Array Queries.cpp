// Memory Limit Exceeded :| :| (32MB GIVEN)

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
#define   sfll2(a,b) 		scanf("%lld%lld",&a,&b)
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

#define   setbit(mask,i) 	mask |= (1<<i) // mask = 1010 i=2 then mask = 1110
#define   clearbit(mask,i) 	mask &= ~(1<<i) // mask = 1010 i=3 then mask = 0010
#define   checkbit(mask,i) 	mask &  (1<<i) // mask = 1010 i=3 then mask = 1000
#define   togglebit(mask,i) mask ^= (1<<bit)

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
vector<ll>TREE[3*100001];
ll arr[100001];
void build(ll node,ll st,ll ed)
{
    if(st==ed)
    {
        TREE[node].push_back(arr[st]);
        return;
    }
    ll mid=(st+ed)/2;
    ll lft=node*2;
    ll rgt=lft+1;
    build(lft,st,mid);
    build(rgt,mid+1,ed);
    merge(TREE[lft].begin(),TREE[lft].end(),TREE[rgt].begin(),TREE[rgt].end(),back_inserter(TREE[node]));
}
ll query1(ll pos, ll l, ll r, ll L, ll R)
{
    if(r < L || R < l) return 1e9;
    if(L <= l && r <= R)//query part
    {
        return TREE[pos][0];
    }
    int mid = (l+r)>>1;
    return min(query1(pos<<1, l, mid, L, R),query1(pos<<1|1, mid+1, r, L, R));
}
ll first=0;
ll query2(ll pos, ll l, ll r, ll L, ll R,ll k)
{
    if(r < L || R < l) return 1e9;
    if(L <= l && r <= R)//query part
    {
        if(binary_search(TREE[pos].begin(),TREE[pos].end(),k))
        {
            if(TREE[pos].size()==1)return 1e9;
            else return TREE[pos][1];
        }
        else
        {
            return TREE[pos][0];
        }
    }
    int mid = (l+r)>>1;
    return min(query2(pos<<1, l, mid, L, R,k),query2(pos<<1|1, mid+1, r, L, R,k));
}
// MAIN FUNCTION
int main()
{
    ll tt,kk=1;
    sfll(tt);
    while(tt--)
    {
        ll n,q;
        sfll2(n,q);
        FOR(i,1,n)
        {
            sfll(arr[i]);
            TREE[i*2].clear();
            TREE[i*2+1].clear();
            TREE[i].clear();
        }
        build(1,1,n);
        cs;
        while(q--)
        {
            ll l,r;
            sfll2(l,r);
            l++;
            r++;
            ll val1=query1(1,1,n,l,r);
            //cout<<val1<<endl;
            first=0;
            ll val2=query2(1,1,n,l,r,val1);
            //cout<<val2<<endl;
            pfll(val2-val1);
            nl;
        }
    }
    return 0;
}


