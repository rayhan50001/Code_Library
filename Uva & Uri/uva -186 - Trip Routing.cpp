//Floyd Warshall (Shortest path with path)
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
#include<bits/stdc++.h>
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
#define Mid(l,r) (l+(r-l)>>1)
#define nl printf("\n")
#define done cout<<"done"<<endl;
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000
#define MX 100010
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define fast ios_base::sync_with_stdio(false);
int power(int x, unsigned int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res*x;
        y = y>>1;
        x = x*x;
    }
    return res;
}
template<typename T>inline string tostring(T a)
{
    ostringstream os("");
    os << a;
    return os.str();
}
template<typename T>inline ll tolong(T a)
{
    ll res;
    istringstream os(a);
    os>>res;
    return res;
}
template<typename T>inline vi parse(T str)
{
    vi res;
    int s;
    istringstream os(str);
    while(os>>s)res.pb(s);
    return res;
}
ll SQRT(ll n){ll e=sqrt(n*1.0);ll l=max(0LL,e-2),r=min(n,e+2);ll ans=0;while(l<=r){ll m=Mid(l,r);if(m*m<=n)ans=m,l=m+1;else r=m-1;}return ans;}
ll CBRT(ll n){ll e=cbrt(n*1.0);ll l=max(0LL,e-2),r=min(n,e+2);ll ans=0;while(l<=r){ll m=Mid(l,r);if(m*m*m<=n)ans=m,l=m+1;else r=m-1;}return ans;}
template< class T > inline T _bigmod(T n,T m)
{
    T ans=1,mult=n%mod;
    while(m)
    {
        if(m & 1) ans=(ans*mult)%mod;
        m>>=1;
        mult=(mult*mult)%mod;
    }
    ans%=mod;
    return ans;
}
template< class T > inline T _modinv(T x)
{
    return _bigmod(x,(T) mod-2)%mod;
}
inline int len(string a)
{
    return a.length();
}
inline int len(char a[])
{
    return strlen(a);
}
template<class T> inline T _gcd(T a, T b)
{
    return (b==0) ? a : _gcd(b, a % b);
}
template< class T > inline T _lcm(T x,T y)
{
    return x*y/_gcd(x,y);
}
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
namespace fastio{
    int ptr, ye;
    char temp[25], str[8333667], out[8333669];

    void init(){
        ptr = 0, ye = 0;
        fread(str, 1, 8333667, stdin);
    }

    inline int number(){
        int i, j, val = 0;

        while (str[ptr] < 45 || str[ptr] > 57) ptr++;
        while (str[ptr] > 47 && str[ptr] < 58) val = (val << 1) + (val << 3) + (str[ptr++] - 48);
        return val;
    }

    inline void convert(long long x){
        int i, d = 0;

        for (; ;){
            temp[++d] = (x % 10) + 48;
            x /= 10;
            if (!x) break;
        }
        for (i = d; i; i--) out[ye++] = temp[i];
        out[ye++] = 10;
    }

    inline void print(){
        fwrite(out, 1, ye, stdout);
    }
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
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
#define fi first
#define se second
map<pair<string,string>,pair<string,int> >mp;
set<string>st;
string str[10001];
map<int,string>dp;
map<string,int>pos;
int graph[1001][1001];
int nextt[1001][1001];
vector<int>path;
void path_find(int i,int j)
{
    do
    {
        path.pb(i);
        int shamne=nextt[i][j];
        i=shamne;
    }while(i!=j);
    path.pb(j);
}
int main()
{
//    clock_t begin = clock();
//    //your code goes here
     //WRITE;
      string s;
      for(int i=1; i<=800; i++)
      {
          for(int j=i+1; j<=800; j++)
          {
            graph[i][j]=inf;
            graph[j][i]=inf;
            nextt[i][j]=j;
            nextt[j][i]=i;
           }
           graph[i][i]=0;
           nextt[i][i]=i;
      }
      int len=0;
      while(1)
      {
          getline(cin,s);
          if(s.empty())break;
          string f,se,t,fo;
          int sta=0;
          for(int i=0; i<s.size(); i++)
          {
              if(s[i]==','){sta=i;break;}
              f+=s[i];
          }
          for(int i=sta+1; i<s.size(); i++)
          {
              if(s[i]==','){sta=i;break;}
              se+=s[i];
          }
          for(int i=sta+1; i<s.size(); i++)
          {
              if(s[i]==','){sta=i;break;}
              t+=s[i];
          }
          for(int i=sta+1; i<s.size(); i++)
          {
              if(s[i]==','){sta=i;break;}
              fo+=s[i];
          }
          int u;
          int v;
          if(pos.find(f)!=pos.end())u=pos[f];
          else
          {
              u=pos[f]=++len;
              dp[len]=f;
          }
          if(pos.find(se)!=pos.end())v=pos[se];
          else
          {
              v=pos[se]=++len;
              dp[len]=se;
          }
          int w = atoi(fo.c_str());
          if( w < graph[u][v] )
          {
            graph[u][v]=graph[v][u]=w;
            mp[{f,se}]={t,w};
            mp[{se,f}]={t,w};
          }
      }

      for(int k=1; k<=len; k++)
      {
          for(int i=1; i<=len; i++)
          {
              for(int j=1; j<=len; j++)
              {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                graph[i][j] = graph[i][k] + graph[k][j];
                nextt[i][j] = nextt[i][k];
                }
              }
          }
      }
      s.clear();
      while(getline(cin,s))
      {
          printf("\n\n");
          string f,se;
          int sta=0;
          for(int i=0; i<s.size(); i++)
          {
              if(s[i]==','){sta=i;break;}
              f+=s[i];
          }
          for(int i=sta+1; i<s.size(); i++)
          {
              if(s[i]==','){sta=i;break;}
              se+=s[i];
          }
          int start=pos[f];
          int end=pos[se];
          cout<<"From                 To                   Route      Miles\n";
          cout<<"-------------------- -------------------- ---------- -----\n";
          path.clear();
          path_find(start,end);
          for(int i=0; i<path.size()-1; i++)
          {
              int u=path[i];
              int v=path[i+1];
              cout<<dp[u];
              int len=dp[u].size();
              for(int i=len; i<20; i++)cout<<" ";
              cout<<" ";
              len=dp[v].size();
              cout<<dp[v];
              for(int i=len; i<20; i++)cout<<" ";
              cout<<" ";
              auto it = mp[{dp[u],dp[v]}];
              string pp = it.first;
              int val = graph[u][v];
              cout<<pp;
              for(int i=pp.size(); i<10; i++)cout<<" ";
              cout<<" ";
              printf("%5d\n",val);
          }
          for(int i=0; i<20; i++)cout<<" ";
          cout<<" ";
          for(int i=0; i<20; i++)cout<<" ";
          cout<<" ";
          for(int i=0; i<10; i++)cout<<" ";
          cout<<" ";
          cout<<"-----\n";
          for(int i=0; i<20; i++)cout<<" ";
          cout<<" ";
          for(int i=0; i<20; i++)cout<<" ";
          cout<<" ";
          cout<<"Total";
          for(int i=5; i<10; i++)cout<<" ";
          cout<<" ";
          printf("%5d\n",graph[start][end]);
      }


//    //end here
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;
//    return 0;
}

