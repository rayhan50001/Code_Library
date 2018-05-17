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
const int MAXN = 40;

struct nodee {
    int next[4];
    int lenn;
    int sufflink;
    int num;
};

int lenn;
char s[MAXN];
nodee Tree[MAXN];
int num;            // node 1 - root with lenn -1, node 2 - root with lenn 0
int suff;           // max suffix palindrome
long long ans;

bool addLetter(int pos) {
    int cur = suff, curlenn = 0;
    int let = s[pos] - 'a';

    while (true) {
        curlenn = Tree[cur].lenn;
        if (pos - 1 - curlenn >= 0 && s[pos - 1 - curlenn] == s[pos])
            break;
        cur = Tree[cur].sufflink;
    }
    if (Tree[cur].next[let]) {
        suff = Tree[cur].next[let];
        return false;
    }

    num++;
    suff = num;
    Tree[num].lenn = Tree[cur].lenn + 2;
    Tree[cur].next[let] = num;

    if (Tree[num].lenn == 1) {
        Tree[num].sufflink = 2;
        Tree[num].num = 1;
        return true;
    }

    while (true) {
        cur = Tree[cur].sufflink;
        curlenn = Tree[cur].lenn;
        if (pos - 1 - curlenn >= 0 && s[pos - 1 - curlenn] == s[pos]) {
            Tree[num].sufflink = Tree[cur].next[let];
            break;
        }
    }

    Tree[num].num = 1 + Tree[Tree[num].sufflink].num;

    return true;
}

void initTree() {
    num = 2; suff = 2;
    Tree[1].lenn = -1; Tree[1].sufflink = 1;
    Tree[2].lenn = 0; Tree[2].sufflink = 1;
}
int CountPS()
{
    lenn=strlen(s);
    for(int i=0; i<40; i++)
    {
        Tree[i].lenn=0;
        Tree[i].sufflink=0;
        Tree[i].num=0;
        for(int j=0; j<3; j++)
        {
        	Tree[i].next[j]=0;
        }
    }
    initTree();
    int ans=0;
    for (int i = 0; i < lenn; i++)
    {
        addLetter(i);
        ans += Tree[suff].num;
    }
    return ans;
}
struct node{
    int val,idx;
    void Merge(node lft, node rht) {
        if(lft.val >= rht.val) {
            val = lft.val;
            idx = lft.idx;
        }
        else if(rht.val > lft.val) {
            val = rht.val;
            idx = rht.idx;
        }
    }
}tree[4*10006];
#define base 37
int palin[10009];
unordered_map<ull,int>mp;
ull power[31];
void build(int idx,int l,int r)
{
    if(l==r)
    {
        tree[idx].val=palin[l];
        tree[idx].idx=l;
        return;
    }
    int mid=(l+r)>>1;
    int lft=idx<<1;
    int rgt=lft|1;
    build(lft,l,mid);
    build(rgt,mid+1,r);
    tree[idx].Merge(tree[lft],tree[rgt]);
}
node query(int pos, int l,int r,int L,int R) {
    if(r < L || R < l) {
        node tmp;
        tmp.val = -1, tmp.idx = -1;
        return tmp;
    }

    if(L <= l && r <= R)
        return tree[pos];

    int mid = (l+r)>>1;

    node x = query(pos<<1, l, mid, L, R);
    node y = query(pos<<1|1, mid+1, r, L, R);

    node mrg;
    mrg.Merge(x, y);
    return mrg;
}
void poww()
{
    power[0]=1;
    for(int i=1; i<=30; i++)power[i]=power[i-1]*base;
}
ull HASH(char *s)
{
    ull HASH=0;
    for(ll i=1; i<=len(s); i++)
    {
        HASH=(HASH+(power[i]*(s[i-1]-'a'+1)));
    }
    return HASH;
}
int main()
{
     clock_t begin = clock();
    //your code goes here
    poww();
    int tt;
    sf(tt);
    while(tt--)
    {
        int n,q;
        sf2(n,q);
        for1(i,1,n)
        {
            scanf("%s",s);
            //cout<<s<<endl;
            palin[i]=CountPS();
            //cout<<palin[i]<<endl;
            ull calc_hash=HASH(s);
            mp[calc_hash]=i;
        }
        build(1,1,n);
        for0(i,q)
        {
            char s1[31],s2[31];
            ss(s1);
            ss(s2);
            ull s1_hash=HASH(s1);
            ull s2_hash=HASH(s2);
            int l=mp[s1_hash];
            int r=mp[s2_hash];
            if(l>r)
            {
                int tmp=l;
                l=r;
                r=tmp;
            }
            pf(query(1,1,n,l,r).idx);
            nl;
        }
    }
   //end here
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;
    return 0;
}
