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
int arr[1000009];
struct node{
 node *left,*right;//left child & right child like segment tree
 int sum;//for min,max,sum etc
 node(int a=0,node *b=NULL,node *c=NULL):
     sum(a),left(b),right(c) {};//**constructor
 void build(int l,int r)
 {
     if(l==r)
     {
         sum=arr[l];
         return;
     }// We reached leaf node, No need more links
     left=new node();// Create new node for Left child
     right=new node();// We are creating nodes only when necessary!
     int mid=(l+r)/2;
     left->build(l,mid);//goto left
     right->build(mid+1,r);//goto right
     sum=left->sum+right->sum;//sum of initial child to store in there parent node
 }
 node *update(int l,int r,int pos,int v)
 {
     if(l>pos || r<pos)return this;//out of range
     if(l==r)
     {
         node *nn=new node(sum,left,right);// Leaf Node, create new node and return that.
         nn->sum+=v;//add value
         return nn;// we first cloned our current node, then added v to the value.
     }
     int mid=(l+r)/2;
     node *nn=new node(sum);//Create a new node, as idx in in [l, r]
     nn->left=left->update(l,mid,pos,v);
     nn->right=right->update(mid+1,r,pos,v);
     // Note that 'ret -> left' is new node's left child,
    // But 'left' is current old node's left child.
    // So we call to update idx in left child of old node.
    // And use it's return node as new node's left child. Same for right.
     nn->sum=nn->left->sum + nn->right->sum;
     return nn;// Return the new node to parent.
 }
 int query(int l,int r,int s,int e)
 {
     if(r < s || l > e) return 0;//out of range
     if(s <= l && r <= e) // completely inside
     {
      return sum;  // return value stored in this node
     }
     int mid=(l+r)/2;
     return left->query(l,mid,s,e)+right->query(mid+1,r,s,e);
 }
}*root[100001];
int main()
{
     clock_t begin = clock();
    //your code goes here
    int n;
    sf(n);
    for0(i,n)sf(arr[i]);
    root[0]=new node();
    root[0]->build(0,n-1);
    int k=0;
    int q;
    sf(q);
    for0(i,q)
    {
        int a,b,c,d;
        sf3(a,b,c);
        sf(d);
        if(a==1)
        {
            root[k+1]=root[b]->update(0,n-1,c-1,d);
            k++;
        }
        else
        {
            int ans=root[b]->query(0,n-1,c-1,d-1);
            pf(ans);
            nl;
        }
    }
   //end here
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;
    return 0;
}

