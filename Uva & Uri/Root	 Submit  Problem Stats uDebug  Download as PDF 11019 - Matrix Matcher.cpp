#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define base 37
#define ll long long
ll HASH[1005][1005];
char grid[1005][1005];
ll pp[1005][1005];
ll power[1000009];
ll dp[1005][1005];
void pre()
{
    power[0]=1;
    for(int i=1; i<=1000001; i++)power[i]=(power[i-1]%MOD*base%MOD)%MOD;
}
void ext_gcd ( long long A, long long B, long long *X, long long *Y ){
    long long x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
}
long long modInv ( long long a, long long m )
{
    long long x, y;
    ext_gcd( a, m, &x, &y );
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}

void calculate(int n,int m)
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < m; c++)
        {
            dp[r + 1][c + 1] = dp[r + 1][c] + dp[r][c + 1] + HASH[r][c] - dp[r][c];
        }
    }
}
ll sumRegion(int row1, int col1, int row2, int col2)
{
    return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
}
bool isvalid(int x,int y,int n,int m)
{
    if(x>=0 && y>=0 && x<n && y<m)return true;
    else return false;
}
ll addMod(ll a, ll b, ll m)
{
    if (a + b < 0)
        return (a - m) + b;
    else if (a + b >= m)
        return a + b - m;
    else
        return a + b;
}
ll multiplyMod(ll a, ll b, ll m)
{
    if (b == 0 || a <=LLONG_MAX / b)
        return (a * b) % m;
    ll result = 0;
    if (a > b) swap(a,b);
    while (a > 0)
    {
        if ((a & 1) != 0)
        {
            result = addMod(result, b, m);
        }
        a >>= 1;
        b -= m - b;
        if (b < 0)
            b += m;
    }
    return result;
}
ll bigMod(ll b,ll p,ll m)
{
    ll x=1,y=b%m;
   while(p>0)
   {
       if(p%2==1)
       {
           x=multiplyMod(x,y,m);
       }
       y=multiplyMod(y,y,m);
       p=p/2LL;
   }
   return x;
}
int main()
{
    //freopen("out.txt","w",stdout);
    pre();
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>grid[i][j];
            }
        }
        for(int i=0; i<=n; i++)
            for(int j=0; j<=m; j++)
            {
                dp[i][j]=0;
                HASH[i][j]=0;
                pp[i][j]=0;
            }
        int l=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                HASH[i][j]=(grid[i][j]%MOD*power[l]%MOD)%MOD;
                //cout<<HASH[i][j]<<" ";
                pp[i][j]=l;
                l++;
            }
            //cout<<endl;
        }
        //cout<<endl;
        calculate(n,m);
        int x,y;
        cin>>x>>y;
        ll pattern=0;
        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                char ch;
                cin>>ch;
                pattern+=(ch*power[pp[i][j]])%MOD;
            }
        }
        if(pattern<0)pattern+=MOD;
        //cout<<pattern<<endl;
        int c=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int ni=i+x-1;
                int nj=j+y-1;
                if(isvalid(ni,nj,n,m))
                {
                    int position=pp[i][j];
                    //cout<<i<<" "<<j<<" "<<ni<<" "<<nj<<endl;
                    ll md=bigMod(power[position],MOD-2,MOD)%MOD;
                    //cout<<"===> "<<md<<endl;
                    ll sum=sumRegion(i,j,ni,nj)%MOD;
                    //cout<<"===>> "<<sum<<endl;
                    ll curr_sum=(md%MOD*sum%MOD)%MOD;
                    //cout<<curr_sum<<endl;
                    if(curr_sum<0)curr_sum+=MOD;
                    if(curr_sum==pattern)c++;
                }
            }
        }
        cout<<c<<endl;
    }
}
