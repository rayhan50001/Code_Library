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
//#define c# printf("Case #%d: ",kk++)
#define nl printf("\n")
#define done cout<<"done"<<endl;
#define eps 1e-9
#define mod 1e9+7
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
struct query{
int l,r,k;
int pos,type;
};
vector<query>v;
int res[1000009];
int tree[4*100009];
bool cmp(query p1,query p2)
{
    if(p1.k==p2.k)
    {
        return p1.type>p2.type;
    }
    else return p1.k>p2.k;
}
void build(int idx,int l,int r)
{
    if(l==r)
    {
        tree[idx]=0;
        return;
    }
    int mid=(l+r)>>1;
    int lft=idx*2;
    int rgt=lft+1;
    build(lft,l,mid);
    build(rgt,mid+1,r);
    tree[idx]=tree[lft]+tree[rgt];
}
void update(int idx,int l,int r,int pos,int val)
{
    if(l==pos && r==pos)
    {
        tree[idx]+=val;
        return;
    }
    int mid=(l+r)>>1;
    int lft=idx*2;
    int rgt=lft+1;
    if(pos<=mid)update(lft,l,mid,pos,val);
    else update(rgt,mid+1,r,pos,val);
    tree[idx]=tree[lft]+tree[rgt];
}
int Query(int idx,int l,int r,int s,int e)
{
    if(l==s && r==e)
    {
        return tree[idx];
    }
    int lft=2*idx;
    int rgt=2*idx+1;
    int mid=(l+r)/2;
    if(e<=mid)
    {
        Query(lft,l,mid,s,e);
    }
    else if(s>mid)
    {
        Query(rgt,mid+1,r,s,e);
    }
    else
    {
        int q1=Query(lft,l,mid,s,mid);
        int q2=Query(rgt,mid+1,r,mid+1,e);
        //return min(q1,q2);
        return q1+q2;
    }
}
int main()
{
     clock_t begin = clock();
    //your code goes here
    clr(tree);
    clr(res);
    int n;
    sf(n);
    build(1,1,n);
    query inp;
    for0(i,n)
    {
        int x;
        sf(x);
        inp.l=i;
        inp.r=i;
        inp.k=x;
        inp.pos=i+1;
        inp.type=1;
        v.push_back(inp);
    }
    int q;
    sf(q);
    query qu;
    for0(i,q)
    {
        int l,r,k;
        sf3(l,r,k);
        qu.l=l;
        qu.r=r;
        qu.k=k;
        qu.pos=i;
        qu.type=2;
        v.push_back(qu);
    }
    sort(all(v),cmp);
    int c=0;
    for(int i=0; i<v.size(); i++)
    {
        //cout<<v[i].type<<" "<<v[i].k<<endl;
        if(v[i].type==1)
        {
            c++;
            update(1,1,n,v[i].pos,1);
            //cout<<v[i].pos<<endl;
            //cout<<Query(1,1,n,v[i].pos,v[i].pos)<<endl;
        }
        else
        {
//            cout<<v[i].l<<" "<<v[i].r<<" "<<v[i].k<<endl;
//            cout<<Query(1,1,n,1,n)<<endl;cout<<"updated: "<<c<<endl;
            res[v[i].pos]=Query(1,1,n,v[i].l,v[i].r);
        }
    }
    //cout<<Query(1,1,n,1,5)<<endl;
    for(int i=0; i<q; i++)
    {
        pf(res[i]);
        nl;
    }
   //end here
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;
    return 0;
}

