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
ll SQRT(ll n)
{
    ll e=sqrt(n*1.0);
    ll l=max(0LL,e-2),r=min(n,e+2);
    ll ans=0;
    while(l<=r)
    {
        ll m=Mid(l,r);
        if(m*m<=n)ans=m,l=m+1;
        else r=m-1;
    }
    return ans;
}
ll CBRT(ll n)
{
    ll e=cbrt(n*1.0);
    ll l=max(0LL,e-2),r=min(n,e+2);
    ll ans=0;
    while(l<=r)
    {
        ll m=Mid(l,r);
        if(m*m*m<=n)ans=m,l=m+1;
        else r=m-1;
    }
    return ans;
}
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
namespace fastio
{
int ptr, ye;
char temp[25], str[8333667], out[8333669];

void init()
{
    ptr = 0, ye = 0;
    fread(str, 1, 8333667, stdin);
}

inline int number()
{
    int i, j, val = 0;

    while (str[ptr] < 45 || str[ptr] > 57) ptr++;
    while (str[ptr] > 47 && str[ptr] < 58) val = (val << 1) + (val << 3) + (str[ptr++] - 48);
    return val;
}

inline void convert(long long x)
{
    int i, d = 0;

    for (; ;)
    {
        temp[++d] = (x % 10) + 48;
        x /= 10;
        if (!x) break;
    }
    for (i = d; i; i--) out[ye++] = temp[i];
    out[ye++] = 10;
}

inline void print()
{
    fwrite(out, 1, ye, stdout);
}
}
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
char mat1[1001][1001];
char mat2[1001][1001];
int n;
char ans[1001][1001];
char calc1[1001][1001];
char calc2[1001][1001];
void rotate90(int p)
{
    int N=n;
    for (int x = 0; x < n/ 2; x++)
    {
        for (int y = x; y < n-x-1; y++)
        {
            char temp = ans[x][y];
            ans[x][y] = ans[y][N-1-x];
            ans[y][N-1-x] = ans[N-1-x][N-1-y];
            ans[N-1-x][N-1-y] = ans[N-1-y][x];
            ans[N-1-y][x] = temp;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(p==1)
                calc1[i][j]=ans[i][j];
            else
                calc1[i][j]=ans[i][j];
        }
    }
}
void rotate270(int p)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(p==1)
                ans[n-j-1][i]=mat1[i][j];
            else
                ans[n-j-1][i]=mat2[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(p==1)
                calc1[i][j]=ans[i][j];
            else
                calc1[i][j]=ans[i][j];
        }
    }

}
void rotate180(int p)
{
    int N=n;
    for (int layer = 0; layer < n / 2; layer++)
    {
        int first = layer;
        int last = n - 1 - layer;
        for (int i = first; i < last; i++)
        {
            int offset = i - first;
            int top = ans[first][i];
            ans[first][i] = ans[last][last - offset];
            ans[last][last - offset] = top;
            int leftBottom = ans[last - offset][first];
            ans[last - offset][first] = ans[i][last];
            ans[i][last] = leftBottom;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(p==1)
                calc1[i][j]=ans[i][j];
            else
                calc1[i][j]=ans[i][j];
        }
    }

}
void rotateV(int p)
{
    int N=n;
    for (int r = 0; r < (n/2); r++)
    {
        for (int c = 0; c != n; ++c)
        {
             swap(ans[r][c], ans[n - 1 - r][c]);
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(p==1)
                calc1[i][j]=ans[i][j];
            else
                calc1[i][j]=ans[i][j];
        }
    }
}
void rotateH(int p)
{
    int N=n;
    char tmp;
    for(int row = 0; row < n  ; row++)
    {
        for (int col = 0; col < n/2 ; col++)
        {
                tmp = ans[row][col];
                ans[row][col] = ans[row][n - 1 - col];
                ans[row][n - 1 - col] = tmp;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(p==1)
                calc1[i][j]=ans[i][j];
            else
                calc1[i][j]=ans[i][j];
        }
    }
}
bool same(int p)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(p==1){
            if(calc1[i][j]!=mat2[i][j])return false;
            }
            else
            {
               if(calc2[i][j]!=mat1[i][j])return false;
            }
        }
    }
    return true;
}
int main()
{
//    clock_t begin = clock();
//    //your code goes here
    int arr[10]= {1,2,3,4,5};
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>mat1[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>mat2[i][j];
        }
    }
    int f=0;
    do{
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                    ans[i][j]=mat1[i][j];
            }
        }
        if(arr[0]==1)rotate90(1);
        if(same(1))
        {
            f=1;
            break;
        }
        if(arr[1]==2)rotate270(1);
        if(same(1))
        {
            f=1;
            break;
        }
        if(arr[2]==3)rotate180(1);
        if(same(1))
        {
            f=1;
            break;
        }
        if(arr[3]==4)rotateH(1);
        if(same(1))
        {
            f=1;
            break;
        }
        if(arr[4]==5)rotateV(1);
        if(same(1))
        {
            f=1;
            break;
        }
    }while(next_permutation(arr,arr+5));
    if(f)cout<<"Yes\n";
    else cout<<"No\n";
//    //end here
//    clock_t end = clock();
//    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
//    cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;
//    return 0;
}

