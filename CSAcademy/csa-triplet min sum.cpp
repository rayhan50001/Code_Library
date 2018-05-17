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
#define inf INT_MAX
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
#define sz(x) x.size()
#define pb push_back
#define left 2 * i + 1
#define right 2 * i + 2
using namespace std;

const int maxn = 1000001;

// the graph
vector<vector<int>> g(maxn);
int level[maxn];
vector<int> e;
vector<int> l;
int h[maxn];
int st[5 * maxn];
void add_edge(int u, int v)
{
    g[u].pb(v);
    g[v].pb(u);
}

// assigning level to nodes
void leveling(int src)
{
    for (int i = 0; i < sz(g[src]); i++)
    {
        int des = g[src][i];
        if (!level[des])
        {
            level[des] = level[src] + 1;
            leveling(des);
        }
    }
}

bool visited[maxn];

// storing the dfs traversal
// in the array e
void dfs(int src)
{
    e.pb(src);
    visited[src] = 1;
    for (int i = 0; i < sz(g[src]); i++)
    {
        int des = g[src][i];
        if (!visited[des])
        {
            dfs(des);
            e.pb(src);
        }
    }
}

// making the array l
void setting_l(int n)
{
    for (int i = 0; i < sz(e); i++)
        l.pb(level[e[i]]);
}

// making the array h
void setting_h(int n)
{
    for (int i = 0; i <= n; i++)
        h[i] = -1;
    for (int i = 0; i < sz(e); i++)
    {
        // if is already stored
        if (h[e[i]] == -1)
            h[e[i]] = i;
    }
}

// Range minimum query to return the index
// of minimum in the subarray L[qs:qe]
int RMQ(int ss, int se, int qs, int qe, int i)
{
    if (ss > se)
        return -1;

    // out of range
    if (se < qs || qe < ss)
        return -1;

    // in the range
    if (qs <= ss && se <= qe)
        return st[i];

    int mid = (ss + se) >> 1;
    int st = RMQ(ss, mid, qs, qe, left);
    int en = RMQ(mid + 1, se, qs, qe, right);

    if (st != -1 && en != -1)
    {
        if (l[st] < l[en])
            return st;
        return en;
    }
    else if (st != -1)
        return st;
    else if (en != -1)
        return en;
}

// constructs the segment tree
void SegmentTreeConstruction(int ss, int se, int i)
{
    if (ss > se)
        return;
    if (ss == se) // leaf
    {
        st[i] = ss;
        return;
    }
    int mid = (ss + se) >> 1;

    SegmentTreeConstruction(ss, mid, left);
    SegmentTreeConstruction(mid + 1, se, right);

    if (l[st[left]] < l[st[right]])
        st[i] = st[left];
    else
        st[i] = st[right];
}

// Funtion to get LCA
int LCA(int x, int y)
{
    if (h[x] > h[y])
        swap(x, y);
    return e[RMQ(0, sz(l) - 1, h[x], h[y], 0)];
}

int main()
{
     clock_t begin = clock();
    //your code goes here
    int n,q;
    sf2(n,q);
    for(int i=0; i<n-1; i++)
    {
        int u,v;
        sf2(u,v);
        add_edge(u,v);
    }
    level[1] = 1;
    leveling(1);
    dfs(1);
    setting_l(n);
    setting_h(n);
    SegmentTreeConstruction(0, sz(l) - 1, 0);
    for(int i=0; i<q; i++)
    {
        int a,b,c,d=0;
        sf3(a,b,c);
        int aa=LCA(a,b);
        d=aa;
        int sum1=l[d]+l[c]-2*l[LCA(c,d)]+1;
        int sum2=l[a]+l[b]-2*l[LCA(b,a)]+1;
        int bb=LCA(a,c);
        d=bb;
        int sum4=l[d]+l[b]-2*l[LCA(b,d)]+1;
        int sum5=l[a]+l[c]-2*l[LCA(a,c)]+1;
        int cc=LCA(b,c);
        d=cc;
        int sum7=l[d]+l[a]-2*l[LCA(a,d)];
        int sum8=l[b]+l[c]-2*l[LCA(b,c)];
        if(l[aa]>=l[bb] && l[aa]>=l[cc])
        {
            d=aa;
        }
        else if(l[bb]>=l[aa] && l[bb]>=l[cc])
        {
            d=bb;
        }
        else d=cc;
        pf(d);
        printf(" ");
        int ans=max({sum1+sum2,sum4+sum5,sum7+sum8});
        pf(ans);
        nl;
    }
   //end here
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;
    return 0;
}

