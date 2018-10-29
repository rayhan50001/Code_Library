//Bismillahir-Rahmanir-Rahim (In The Name Of ALLAH)

//everything is long long

#include<bits/stdc++.h>
//#include<unordered_map>

using namespace std;

//... Define Section

#define   mem(a,val)		memset(a,val,sizeof(a))
#define   all(a)		    a.begin(),a.end()
#define   sz(A) 		    A.size()
#define   len(A)		    strlen(A)
#define   ff                first
#define   ss                second
#define   pb 			    push_back
#define   PI			    acos(-1.00)
#define   ll			    long long
#define   pii			    pair<ll,ll>
#define   READ 		        freopen("input.txt", "r", stdin)
#define   WRITE 		    freopen("output.txt", "w", stdout)
#define   FOR(i,a,b) 		for(int i=a;i<=b;i++)
#define   RFOR(i,a,b) 		for(int i=a;i>=b;i--)
#define   sfll(a) 		    scanf("%lld",&a)
#define   sfll2(a,b) 		scanf("%lld %lld",&a,&b)
#define   sfll3(a,b,c) 	    scanf("%lld%lld%lld",&a,&b,&c)
#define   cs 			    printf("Case %lld: ",kk++)
#define   cn 			    printf("Case %lld:\n",kk++)
#define   pfll(a) 		    printf("%lld",a)
#define   nl			    printf("\n")
#define   done 		        printf("DONE\n")
#define   EPS			    1e-9
#define   MOD 			    1000000007
#define   MAX			    1e6
#define   fast 		        ios_base::sync_with_stdio(false);

//BitMask Section

#define   checkBit(S, j)    (S & (1 << j))
#define   setBit(S, j)      (S |= (1 << j))
#define   clearBit(S, j)    (S &= ~(1 << j))
#define   toggleBit(S, j)   (S ^= (1 << j))
#define   lowBit(S)         (S & (-S))
#define   setAll(S, n)      (S = (1 << n) - 1)
//Default Function

template<typename T>inline string Tostring(T a){ostringstream os("");os << a;return os.str();} //number to string
template<typename T>inline ll Tolong(T a){ll res;istringstream os(a);os>>res;return res;} //string to number
template< class T > inline T Bigmod(T n,T m,T mod){T ans=1,mult=n%mod;while(m){if(m & 1) ans=(ans*mult)%mod;m>>=1;mult=(mult*mult)%mod;}ans%=mod;return ans;}//Big Mod (A^B)%M
template< class T > inline T Modinv(T x,T mod){return _bigmod(x,(T) mod-2)%mod;} // Modular Inverse (A/B=A^(-B))%M
template<typename T>inline vector<int> Parse(T str){vector<int> res;int s;istringstream os(str);while(os>>s)res.pb(s);return res;}//string to vector
template< class T > inline T Lcm(T x,T y){return x*y/__gcd(x,y);}//LCM (a*b)/gcd(a,b)
template<typename T> inline T pwr(T b, T p) {T res  = 1;while(p > 0) {if(p&1) {res *= b ;}b *= b;p >>= 1;}return res ;}//power a^b
template <typename T>inline vector< T > Unique(vector< T > v) {sort(v.begin(), v.end());v.erase(unique(v.begin(), v.end()),v.end());return v;}// 1 2 1 3 = 1 2 3 (vector)


//Direction Array

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

//Running Time

clock_t begn,ed;
double time_spent;
#define   timestart()		begn=clock()
#define   timestop()		ed=clock()
void      timelimit()		{time_spent = (double)(ed - begn) / CLOCKS_PER_SEC;cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;}
// start coding

int main()
{
    ll tt;
    sfll(tt);
    while(tt--)
    {
       ll n,k;
       sfll2(n,k);
       ll kk=k;
       vector<ll>v;
       if((k*(k+1LL)/2LL) > n)
       {
            pfll(-1LL);
       }
       else if(k==1)
       {
           ll ans=((n%MOD*n%MOD)%MOD-n+MOD)%MOD;
           pfll(ans);
       }
       else
       {
            if(k%2==0 && n%k==0)
            {
                ll mid=n/k;
                ll age=mid-1;
                ll pore=mid+1;
                while(1)
                {
                    v.pb(age--);
                    v.pb(pore++);
                    k-=2;
                    if(k==0)break;
                }
            }
            else
            {
                //cout<<"FF"<<endl;
                ll mid = n/k;
                ll age = mid;
                ll pore = mid;
                v.pb(mid);
                k--;
                ll sum=0;
                sum+=mid;
                while(1)
                {
                    ++pore;
                    v.pb(pore);
                    sum+=pore;
                    k--;
                    if(k == 0)break;
                    --age;
                    sum+=age;
                    v.pb(age);
                    k--;
                    if(k == 0)break;
                }
                sort(v.begin(),v.end());
                //cout<<sum<<endl;
                if(sum>n)
                {
                    ll left=sum-n;
                    ll len_minus=(left%kk);
                    for(int i=0; i<len_minus; i++)v[i]-=1;
                }
                if(sum<n)
                {
                    ll left=n-sum;
                    ll len_minus=(left%kk);
                    reverse(v.begin(),v.end());
                    for(int i=0; i<len_minus; i++)v[i]++;
                    reverse(v.begin(),v.end());
                }
            }
             ll ans=1;
             ll sum=0;
             for(int i=0; i<kk; i++)
             {
               sum+=v[i];
               //cout<<v[i]<<" ";
               //if(v[i] == 1) { ans=0; break; }
               ans =(ans%MOD*(((v[i]%MOD*v[i]%MOD)%MOD-v[i]%MOD+MOD)+MOD)%MOD)%MOD;
               if(ans<0)ans+=MOD;
            }
            //cout<<endl;
            //if(sum==n)cout<<"yes\n";
            if(sum>n || sum<n)ans=0;
            //if(sum>n || sum<n)ans=0;
            if(ans<0)ans+=MOD;
            pfll(ans);
       }
       nl;
    }
}



