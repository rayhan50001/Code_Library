//shortest path
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
#define mem(a) memset(a,100000000,sizeof(a))
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
#define inf INT_MAX
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
int graph[1001][1001];
int cost[1001];
int vis[1001];
int dist[1001];
int par[1001];
int main()
{
//    clock_t begin = clock();
//    //your code goes here
      //READ;
      //WRITE;
      int t,tt=1;
      sf(t);
      while(getchar()!='\n');
      while(getchar()!='\n');
      while(t--)
      {
          string s;
          getline(cin,s);
          stringstream in(s);
          int n=1;
          while(in>>graph[1][n])n++;
          n--;
          for(int i=2; i<=n; i++)
          {
              for(int j=1; j<=n; j++)
              {
                  sf(graph[i][j]);
              }
          }
          for(int i=1; i<=n; i++)
          {
            sf(cost[i]);
          }
          while(getchar() != '\n');
          s.clear();
          int pp=1;
          while(getline(cin,s) && s[0])
          {
            if(pp++>1)cout<<endl;
            stringstream in(s);
            int st,ed;
            in>>st;
            in>>ed;
            for(int i=1; i<=n; i++)dist[i]=0xfffffff,vis[i]=0,par[i]=i;
            dist[st]=0;
            queue<int>Q;
            Q.push(st);
            while(!Q.empty())
            {
                int x=Q.front();
                Q.pop();
                for(int i=1; i<=n; i++)
                {

                    if(graph[x][i]==-1)continue;
                    //cout<<dist[i]<<" "<<dist[x]+cost[i]+graph[x][i]<<endl;
                    if(dist[i]>dist[x]+cost[i]+graph[x][i])
                    {
                        dist[i]=dist[x]+cost[i]+graph[x][i];
                        par[i]=x;
                        if(vis[i]==0)
                        {
                            vis[i]=1;
                            Q.push(i);
                        }
                    }
                }
            }
            cout<<"From "<<st<<" to "<<ed<<" :\n";
            int stk[105], stkidx = 0;
            int x = ed;
            while(x != st) {
                stk[stkidx++] = x;
                x = par[x];
            }
            printf("Path: %d", st);
            for(int i = stkidx-1; i >= 0; i--)
                printf("-->%d", stk[i]);
            if(st == ed)
            {
                printf("-->%d", ed);
                dist[ed] = cost[ed];
            }
            cout<<endl;
            printf("Total cost : %d\n", dist[ed]-cost[ed]);
          }

      }
//    //end here
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;
//    return 0;
}
//another
#include <stdio.h>
#include <sstream>
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int t;
    char s[505];
    int g[505][505], gv[505];
    scanf("%d", &t);
    while(getchar() != '\n');
    while(getchar() != '\n');
    while(t--) {
        gets(s);
        stringstream sin(s);
        int n = 1, x, y, i, j;
        while(sin >> g[1][n])
            n++;
        n--;
        for(i = 2; i <= n; i++)
            for(j = 1; j <= n; j++)
                scanf("%d", &g[i][j]);
        for(i = 1; i <= n; i++)
            scanf("%d", &gv[i]);
        while(getchar() != '\n');
        int pflag = 0;
        while(gets(s) && s[0]) {
            if(pflag)   puts("");
            pflag = 1;
            int st, ed;
            int dis[505] = {}, used[505] = {}, prev[505];
            sscanf(s, "%d %d", &st, &ed);
            for(i = 1; i <= n; i++)
                dis[i] = 0xfffffff;
            dis[st] = 0;
            queue<int> Q;
            Q.push(st);
            while(!Q.empty()) {
                x = Q.front(), Q.pop();
                used[x] = 0;
                for(i = 1; i <= n; i++) {
                    if(g[x][i] == -1)
                        continue;
                    if(dis[i] > dis[x]+gv[i]+g[x][i]) {
                        dis[i] = dis[x]+gv[i]+g[x][i];
                        prev[i] = x;
                        if(used[i] == 0) {
                            used[i] = 1;
                            Q.push(i);
                        }
                    }
                }
            }
            printf("From %d to %d :\n", st, ed);
            int stk[105], stkidx = 0;
            x = ed;
            while(x != st) {
                stk[stkidx++] = x;
                x = prev[x];
            }
            printf("Path: %d", st);
            for(i = stkidx-1; i >= 0; i--)
                printf("-->%d", stk[i]);
            if(st == ed) {
                printf("-->%d", ed);
                dis[ed] = gv[ed];
            }
            puts("");
            printf("Total cost : %d\n", dis[ed]-gv[ed]);
        }
        if(t)
            puts("");
    }
    return 0;
}

