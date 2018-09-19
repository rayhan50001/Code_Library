#include<bits/stdc++.h>
using namespace std;
#define MOD1 1000000007
#define MOD2 1000000009
#define base1 31
#define base2 37
#define ll long long
#define fast ios_base::sync_with_stdio(false);
ll HASH1[1005][1005];
//ll HASH2[1005][1005];
char grid[1005][1005];
ll pp[1005][1005];
ll power1[1000009];
//ll power2[1000009];
ll dp1[1005][1005];
//ll dp2[1005][1005];
void pre()
{
    power1[0]=1;
    for(int i=1; i<=1000001; i++)power1[i]=(power1[i-1]%MOD1*base1%MOD1)%MOD1;
    //power2[0]=1;
    //for(int i=1; i<=1000001; i++)power2[i]=(power2[i-1]%MOD2*base2%MOD2)%MOD2;
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
            dp1[r + 1][c + 1] = (((dp1[r + 1][c]%MOD1 + dp1[r][c + 1]%MOD1 + HASH1[r][c]%MOD1)%MOD1) - dp1[r][c]%MOD1+MOD1)%MOD1;
            //dp2[r + 1][c + 1] = (((dp2[r + 1][c]%MOD2 + dp2[r][c + 1]%MOD2 + HASH2[r][c]%MOD2)%MOD2) - dp2[r][c]%MOD2+MOD2)%MOD2;
        }
    }
}
ll sumRegion1(int row1, int col1, int row2, int col2)
{
    return (dp1[row2 + 1][col2 + 1]%MOD1 - dp1[row1][col2 + 1]%MOD1 - dp1[row2 + 1][col1]%MOD1 + dp1[row1][col1]%MOD1+MOD1)%MOD1;
}
//ll sumRegion2(int row1, int col1, int row2, int col2)
//{
//    return (dp2[row2 + 1][col2 + 1]%MOD2 - dp2[row1][col2 + 1]%MOD2 - dp2[row2 + 1][col1]%MOD2 + dp2[row1][col1]%MOD2+MOD2)%MOD2;
//}
bool isvalid(int x,int y,int n,int m)
{
    if(x>=0 && y>=0 && x<n && y<m)return true;
    else return false;
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
int main()
{
    //freopen("out.txt","w",stdout);
    //cout<<modInv(31,MOD1)<<endl;
    fast;
    pre();
    int tt;
    fastIn(tt);
    while(tt--)
    {
        int n,m;
        fastIn(n);
        fastIn(m);
        for(int i=0; i<n; i++)
        {
            scanf("%s",grid[i]);
        }

        for(int i=0; i<=n; i++)
            for(int j=0; j<=m; j++)
            {
                dp1[i][j]=0;
                HASH1[i][j]=0;
                //dp2[i][j]=0;
                //HASH2[i][j]=0;
                pp[i][j]=0;
            }
        int l=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                HASH1[i][j]=(grid[i][j]%MOD1*power1[l]%MOD1)%MOD1;
                //HASH2[i][j]=(grid[i][j]%MOD2*power2[l]%MOD2)%MOD2;
                //cout<<HASH1[i][j]<<" ";
                pp[i][j]=l;
                l++;
            }
            //cout<<endl;
        }
        //cout<<endl;
        calculate(n,m);
        int x,y;
        fastIn(x);
        fastIn(y);
        ll pattern1=0;
        ll pattern2=0;
        for(int i=0; i<x; i++)
        {
            char ch[101];
            scanf("%s",ch);
            for(int j=0; j<y; j++)
            {
                //cout<<pp[i][j]<<" ";
                pattern1=(pattern1%MOD1+(ch[j]*power1[pp[i][j]]%MOD1)%MOD1)%MOD1;
                //pattern2=(pattern2%MOD2+(ch[j]*power2[pp[i][j]]%MOD2)%MOD2)%MOD2;
            }
            //cout<<endl;
        }
        if(pattern1<0)pattern1+=MOD1;
        //if(pattern2<0)pattern2+=MOD2;
        //cout<<pattern1<<" "<<pattern2<<endl;
        ll c=0;
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
                    ll md1=modInv(power1[position],MOD1)%MOD1;
                    //ll md2=modInv(power2[position],MOD2)%MOD2;
                    if(md1<0)md1+=MOD1;
                    //if(md2<0)md2+=MOD2;
                    //cout<<"===> "<<md<<endl;
                    ll sum1=sumRegion1(i,j,ni,nj)%MOD1;
                    //ll sum2=sumRegion2(i,j,ni,nj)%MOD2;
                    if(sum1<0)sum1+=MOD1;
                    //if(sum2<0)sum2+=MOD2;
                    //cout<<"===>> "<<sum<<endl;
                    ll curr_sum1=(md1%MOD1*sum1%MOD1)%MOD1;
                    //ll curr_sum2=(md2%MOD2*sum2%MOD2)%MOD2;
                    //cout<<curr_sum1<<" "<<curr_sum2<<endl;
                    //system("pause");
                    if(curr_sum1<0)curr_sum1+=MOD1;
                    //if(curr_sum2<0)curr_sum2+=MOD2;
                    if(curr_sum1==pattern1)c++;
                }
            }
        }
        printf("%lld\n",c);
    }
}
