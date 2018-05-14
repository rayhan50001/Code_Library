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
#define c# printf("Case #%d: ",kk++)
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
ll arr[1000009];
ll mx[1000009];
ll fr[1000009];
int main()
{
     clock_t begin = clock();
    //your code goes here
    ll n;
    sfll(n);
    for(ll i=0; i<n; i++)sfll(arr[i]),fr[arr[i]]++;
    ll sorted=1;
    for(ll i=1; i<n; i++)
    {
        if(arr[i]>=arr[i-1])continue;
        sorted=0;
    }
    if(sorted)
    {
         //cout<<"yes\n";
        ll ans=0;
        for(ll i=0; i<n; i++)
        {
            ll nn=fr[arr[i]];
            ans+=nn;
            fr[arr[i]]--;
        }
        cout<<ans<<endl;
        cout<<1<<" "<<1<<endl;
    }
    else
    {
        //cout<<"yes\n";
            mx[0]=arr[0];
            for1(i,1,n-1)
            {
                mx[i]=max(mx[i-1],arr[i]);
            }
            //for0(i,n)pf(mx[i]);
            if(mx[0]>mx[n-1])
            {
                cout<<0<<endl;
            }
            else
            {
                ll start=-1;
                ll endd=-1;
               for(ll i=n-1; i>=0; i--)
               {
                  if(mx[i]==arr[i])continue;
                  ll next=i;
                  ll now=lower_bound(mx,mx+n,mx[i])-mx;
                  ll f=0;
                  //cout<<now<<" "<<next<<endl;
                  for(ll j=next-1; j>=now; j--)
                  {
                      if(arr[j+1]<=arr[j])continue;
                      f=1;
                  }
                  if(!f)
                  {
                      start=now;
                      endd=next;
                  }
                  break;
               }
               if(start==-1 && endd==-1)cout<<0<<endl;
               else
               {
                   int f=0;
                   for(int i=1; i<start; i++)
                   if(arr[i-1]>arr[i]){f=1;break;}
                   if(!f)
                   {
                       arr[endd+1]=arr[start-1];
                       for(int i=endd; i>=start; i--)
                       {
                           //cout<<arr[i+1]<<" "<<arr[i]<<endl;
                           if(arr[i+1]<=arr[i])continue;
                           f=1;
                           break;
                       }
                    if(!f)
                    {
                   cout<<1<<endl;
                   cout<<start+1<<" "<<endd+1<<endl;
                    }
                    else cout<<0<<endl;
                   }
                   else cout<<0<<endl;
               }
            }
            nl;
    }
   //end here
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;
    return 0;
}

