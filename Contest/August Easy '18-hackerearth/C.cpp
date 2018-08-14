#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100009][11];
void pre()
{
    for(int j=1; j<=10; j++)dp[0][j]=0;
    for(int j=1; j<=100005; j++)
    {
        int l=1;
        for(double i=0.1; i<=0.7; i+=0.1)
        {
           dp[j][l]=dp[j-1][l]+floor(i*(double)j);
           l++;
        }
    }
    for(int j=1; j<=100005; j++)
    {
        int l=8;
        for(double i=0.8; i<=1; i+=0.1)
        {
           dp[j][l]=dp[j-1][l]+floor(i*(double)j);
           l++;
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    pre();
    int tt;
    cin>>tt;
    while(tt--)
    {
        //cout<<round(1.5)<<endl;
        ll n,p;
        cin>>n>>p;
        map<ll,ll>check;
        ll sum=(n*(n+1LL))/2LL;
        for(int i=1; i<=10; i++)
        {
            check[dp[n][i]]=1;
            cout<<dp[n][i]<<" ";
        }
        cout<<endl;
        //cout<<n<<" "<<p<<"==> ";
        double dsum=0.0;
        double val;
        cin>>val;
        for(double i=1; i<=n; i++)
        {
            dsum+=floor(i*val);
        }
        cout<<dsum<<endl;
        ll left=p/sum;
        ll baki=p%sum;
        cout<<p-(sum*left)<<endl;
        if(baki==0)baki=sum;
        if(check[baki])cout<<check[baki]*left<<endl;
        else cout<<-1<<endl;
    }
}
