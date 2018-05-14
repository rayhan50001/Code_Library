//                            ببِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
#include<iostream>
#include<cstdio>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>
#include<deque>
#include<iterator>
#include<assert.h>
#include<bitset>
#include<climits>
#include<ctime>
#include<complex>
#include<unordered_map>
using namespace std;
//define for shortcut
#define mem(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define sz(A) A.size()
#define clr(a) memset(a,0,sizeof(a))
#define pb push_back
#define pi acos(-1.0)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define vpii vector< pair<int,int> >
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define vs vector<string>
#define vi vector<int>
#define vc vector<char>
#define sts set<string>
#define sti set<int>
#define stc set<char>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define ull unsigned long long
#define ll long long
#define for1(i,a,b) for(int i=a;i<=b;i++)
#define rfor1(i,a,b) for(int i=a;i>=b;i--)
#define rfor0(i,a,b) for(int i=a-1;i>b;i--)
#define for0(i,a) for(int i=0;i<a;i++)
//read input
#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sfll(a) scanf("%lld",&a)
#define sfll2(a,b) scanf("%lld%lld",&a,&b)
#define sfll3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define ss(a) scanf("%s",&a)
#define sc(a) scanf("%c",&a)
#define sd(a) scanf("%lf",&a)
#define pf(a) printf("%d",a)
#define pfll(a) printf("%lld",a)
#define pfd(a) printf("%.17f",a)
#define pc(a) printf("%c",a)
#define ps(a) printf("%s",a)
#define cs printf("Case %d: ",kk++)
#define cn printf("Case %d:\n",kk++)
///#define c# printf("Case #%d: ",kk++)
#define nl printf("\n")
#define done cout<<"done"<<endl;
#define eps 1e-9
#define mod 1000000007
#define INF INT_MAX
#define MX 100010
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define fast ios_base::sync_with_stdio(false);
template<typename T>inline string tostring(T a){ostringstream os("");os << a;return os.str();}
template<typename T>inline ll tolong(T a){ll res;istringstream os(a);os>>res;return res;}
template<typename T>inline vi parse(T str){vi res;int s;istringstream os(str);while(os>>s)res.pb(s);return res;}
template< class T > inline T _sqrt(T x) { return (T) sqrt( (double) x); }
template< class T > inline T _bigmod(T n,T m) {T ans=1,mult=n%mod; while(m){ if(m & 1) ans=(ans*mult)%mod; m>>=1; mult=(mult*mult)%mod; } ans%=mod; return ans;}
template< class T > inline T _modinv(T x) {return _bigmod(x,(T) mod-2)%mod;}
inline int len(string a) {return a.length();}
inline int len(char a[]) {return strlen(a);}
template<class T> inline T _gcd(T a, T b){return (b==0) ? a : _gcd(b, a % b);}
template< class T > inline T _lcm(T x,T y) { return x*y/_gcd(x,y);}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
//bool compare(const pair<float,string>&i, const pair<float,string>&j)
//{
//    return i.first > j.first;
//}
//int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
//int EQ(double d) {
//    if ( fabs(d) < EPS ) return 0;
//    return d > EPS ? 1 : -1 ;
//}
#define MAX 10001
int level[MAX], parent[MAX], ChainHeight[MAX], num[MAX], nextNode[MAX], Top[MAX], Chain[MAX], Tree[4*MAX], val[MAX], pos[MAX], noTonode[MAX];
int Chain_no=1, no=1, n, cnt=0;
vi gr[MAX],weight[MAX];
void build(int pos, int L, int R) {
    if(L == R) {
        Tree[pos] = val[noTonode[L]];
        return;
    }

    int mid = (L+R)>>1;
    build(pos<<1, L, mid);
    build(pos<<1|1, mid+1, R);

    Tree[pos] = max(Tree[pos<<1] , Tree[pos<<1|1]);
}

void Update(int pos, int L, int R, int idx, int val) {
    if(idx < L || R < idx)
        return;

    if(L == R) {
        Tree[pos] = val;
        return;
    }

    int mid = (L+R)>>1;
    Update(pos<<1, L, mid, idx, val);
    Update(pos<<1|1, mid+1, R, idx, val);

    Tree[pos] = max(Tree[pos<<1] , Tree[pos<<1|1]);
}

int query(int pos, int L, int R, int l, int r) {
    if(r < L || R < l)
        return 0;

    if(l <= L && R <= r)
        return Tree[pos];

    int mid = (L+R)>>1;
    int lft = query(pos<<1, L, mid, l, r);
    int rht = query(pos<<1|1, mid+1, R, l, r);
    return max(lft,rht);
}

void dfs(int u,int p,int cost)
{
    parent[u]=p;
    ChainHeight[u]=1;
    val[u]=cost;
    pos[cnt++]=u;
    int len=gr[u].size();
    for(int i=0; i<len; i++)
    {
        int v=gr[u][i];
        if(v!=p)
        {
            level[v]+=level[u]+1;
            dfs(v,u,weight[u][i]);

            ChainHeight[v]+=ChainHeight[u];
            if(nextNode[u]!=-1 || ChainHeight[v]>ChainHeight[nextNode[u]])
                nextNode[u]=v;
        }
    }
}
void HLD(int u,int parent)
{
    Chain[u]=Chain_no;
    num[u]=no++;

    if(ChainHeight[Chain_no]==0)
        Top[Chain_no]=u;

    ChainHeight[Chain_no]++;

    if(nextNode[u]!=-1)
        HLD(nextNode[u],u);

    int len=gr[u].size();
    for(int i=0; i<len; i++)
    {
        int v=gr[u][i];
        if(v!=parent && v!=nextNode[u])
        {
            Chain_no++;
            HLD(v,u);
        }
    }
}
int QUERY(int u,int v)
{
    int res=-INF;
    while(Chain[u]!=Chain[v])
    {
        if(level[Top[Chain[u]]]<level[Top[Chain[v]]])
            swap(u,v);
        int start=Top[Chain[u]];
        res=max(res,query(1,1,n,num[start],num[u]));
        u=parent[start];
    }

    if(num[u]>num[v])swap(u,v);

    res=max(res,query(1,1,n,num[u]+1,num[v]));

    return res;
}
void noTonodeConvert(int n)
{
    for(int i=1; i<=n; i++)
    {
        noTonode[num[i]]=i;
    }
}
int main()
{
     //clock_t begin = clock();
    //your code goes here
    //WRITE;
    int tt;
    sf(tt);
    while(tt--)
    {
        sf(n);
        vpii vp;
        for(int i=1; i<n; i++)
        {
            int u, v, c;
            sf3(u,v,c);

            gr[u].pb(v);
            gr[v].pb(u);

            weight[u].pb(c);
            weight[v].pb(c);

            vp.pb({u,v});
        }
        clr(level);
        memset(nextNode,-1,sizeof nextNode);
        Chain_no=1;
        no=1;
        cnt=0;
        dfs(1,1,-INF);
        clr(ChainHeight);
        HLD(1,1);
        noTonodeConvert(n);
        build(1,1,n);
        while(true)
        {
            char s[10];
            scanf("%s",s);
            if(s[0]=='Q')
            {
                int u,v;
                sf2(u,v);
                int ans=QUERY(u,v);
                if(ans==-INF)ans=0;
                pf(ans);
                nl;
            }
            else if(s[0]=='C')
            {
                int i,v;
                sf2(i,v);
                int uu=vp[i-1].first;
                int vv=vp[i-1].second;
                if(parent[uu]==vv)swap(uu,vv);
                int p=num[vv];
                //cout<<p<<" "<<v<<endl;
                Update(1,1,n,p,v);
            }
            else break;
        }
        for(int i=1; i<=n; i++){gr[i].clear();weight[i].clear();}
    }

   //end here
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;
    return 0;
}

