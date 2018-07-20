//                                ببِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
/*
───────────────────────────────────────────────────────────────────────────────────────────────────────────
─████████████████───██████████████─████████──████████─██████──██████─██████████████─██████──────────██████─
─██░░░░░░░░░░░░██───██░░░░░░░░░░██─██░░░░██──██░░░░██─██░░██──██░░██─██░░░░░░░░░░██─██░░██████████──██░░██─
─██░░████████░░██───██░░██████░░██─████░░██──██░░████─██░░██──██░░██─██░░██████░░██─██░░░░░░░░░░██──██░░██─
─██░░██────██░░██───██░░██──██░░██───██░░░░██░░░░██───██░░██──██░░██─██░░██──██░░██─██░░██████░░██──██░░██─
─██░░████████░░██───██░░██████░░██───████░░░░░░████───██░░██████░░██─██░░██████░░██─██░░██──██░░██──██░░██─
─██░░░░░░░░░░░░██───██░░░░░░░░░░██─────████░░████─────██░░░░░░░░░░██─██░░░░░░░░░░██─██░░██──██░░██──██░░██─
─██░░██████░░████───██░░██████░░██───────██░░██───────██░░██████░░██─██░░██████░░██─██░░██──██░░██──██░░██─
─██░░██──██░░██─────██░░██──██░░██───────██░░██───────██░░██──██░░██─██░░██──██░░██─██░░██──██░░██████░░██─
─██░░██──██░░██████─██░░██──██░░██───────██░░██───────██░░██──██░░██─██░░██──██░░██─██░░██──██░░░░░░░░░░██─
─██░░██──██░░░░░░██─██░░██──██░░██───────██░░██───────██░░██──██░░██─██░░██──██░░██─██░░██──██████████░░██─
─██████──██████████─██████──██████───────██████───────██████──██████─██████──██████─██████──────────██████─
───────────────────────────────────────────────────────────────────────────────────────────────────────────
All Judge ID: rayhan50001 and rayhan5000 and want.to.kill.you
Bangladesh University of Business & Technology(BUBT)
CSE,29th Intake,Section-05
*/
                //*If You Have a Good Personality,You Don't Need To Describe Yourself*\\

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

#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define SZ(A) A.size()
#define CLR(a) memset(a,0,sizeof(a))
#define PB push_back
#define PI acos(-1.0)
#define MP(a,b) make_pair(a,b)
#define PII pair<int,int>
#define VPII vector< pair<int,int> >
#define PCC pair<char,char>
#define PIC pair<int,char>
#define PCI pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define SC vector<char>
#define SS set<string>
#define SI set<int>
#define SC set<char>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define LL long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define RFOR(i,a,b) for(int i=a;i>=b;i--)
#define For(i,a) for(int i=0;i<a;i++)

#define S(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SLL(a) scanf("%lld",&a)
#define SLL2(a,b) scanf("%lld%lld",&a,&b)
#define SLL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
//#define SS(a) scanf("%s",&a)
#define SC(a) scanf("%c",&a)
#define SD(a) scanf("%lf",&a)
#define P(a) printf("%d",a)
#define PLL(a) printf("%lld",a)
#define PD(a) printf("%lf",a)
#define PC(a) printf("%c",a)
#define PS(a) printf("%s",a)
#define KS printf("Case %d: ",kk++)
#define KN printf("Case %d:\n",kk++)
#define KH printf("Case #%d: ",kk++)
#define NL printf("\n")
#define DB cout<<"done"<<endl;
#define YES() cout<<"YES\n";
#define NO() cout<<"NO\n";
#define Yes() cout<<"Yes\n";
#define No() cout<<"No\n";
#define EPS 1e-9
#define MOD 10
#define INF INT_MAX/3
#define MX 100010
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define ansmax -9999999999999999999
template<typename T>inline string tostring(T a){ostringstream os("");os << a;return os.str();}
template<typename T>inline LL tolong(T a){LL res;istringstream os(a);os>>res;return res;}
template<typename T>inline VI parse(T str){VI res;int s;istringstream os(str);while(os>>s)res.PB(s);return res;}
template< class T > inline T _sqrt(T x) { return (T) sqrt( (double) x); }
template< class T > inline T _bigmod(T n,T m) {T ans=1,mult=n%MOD; while(m){ if(m & 1) ans=(ans*mult)%MOD; m>>=1; mult=(mult*mult)%MOD; } ans%=MOD; return ans;}
template< class T > inline T _modinv(T x) {return _bigmod(x,(T) MOD-2)%MOD;}
inline int LEN(string a) {return a.length();}
inline int LEN(char a[]) {return strlen(a);}
template<class T> inline T _gcd(T a, T b){return (b==0) ? a : _gcd(b, a % b);}
template< class T > inline T _lcm(T x,T y) { return x*y/_gcd(x,y);}

//set function to order a tree
//typedef tree<
//int ,
//null_type,
//less<int>,
//rb_tree_tag,
//tree_order_statistics_node_update>pbd_set;
//end set function to order a tree
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
bool compare(const pair<float,string>&i, const pair<float,string>&j)
{
    return i.first > j.first;
}
int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
const int mx = 1e5 + 7;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}
//int n, ans = 0;
//string s[100009];
//vector <int> r, b;
//
/*int conv(string t)
{
    int res = 0;
    for(int i = 0; i < t.size(); i++)
    {
        res = res*10 + (int)(t[i] - '0');
    }
    return res;
}
*/
/*int prime[1000009];
void seive()
{
    prime[1]=1;
    for (int i=2;i<=200000;i++)
    {
        if (prime[i]==0)
        for (int j=i*2;j<=200000;j+=i)
        prime[j]=1;
    }
    for(int i=1; i<=200000; i++)
    {
        if(prime[i])
            cout<<i<<" ";
    }
//    for (int i=200000;i;--i)
//    if (prime[i])
//        add[i]=add[i+1]+1;
////    for(int i=1; i<=11; i++)
////    {
////        cout<<add[i]<<" ";
////    }

}
*/
/*bool Isalpha(char c)
{
    if((c>='a' && c<='z') || c>='A' && c<='Z')
        return true;
    else return false;
}
*/
queue<pair<int,string>>qu;
int a[100020]={0};
    int main(){
               cin.tie(0);
    		ios::sync_with_stdio(false);
int n,k;
cin>>n>>k;
    	string e="0";
    	e[0]+=k;
    	qu.push(make_pair(k,e));
    	while(1)
    	{
    		auto v=qu.front();
    		qu.pop();
    		cout<<v.first<<" "<<v.second<<endl;
    		if(v.first==0){
    			cout<<v.second<<endl;
    			return 0;
    		}
    		if(a[v.first])continue;
    	    a[v.first]=1;
    		qu.push(make_pair((v.first*10),v.second+"0"));
    		qu.push(make_pair((v.first*10+k),v.second+e));
    	}

return 0;

            }
