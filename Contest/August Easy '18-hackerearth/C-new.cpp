#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define double long double
//ll dp[100009][1001];
//void pre()
//{
//    for(int j=1; j<=10; j++)dp[0][j]=0;
//    for(int j=1; j<=100005; j++)
//    {
//        int l=1;
//        for(double i=1; i<=799; i++)
//        {
//           dp[j][l]=dp[j-1][l]+floor(i/100.00*(double)j);
//           l++;
//        }
//    }
//    for(int j=1; j<=100005; j++)
//    {
//        int l=800;
//        for(double i=800; i<=1000; i++)
//        {
//           dp[j][l]=dp[j-1][l]+floor(i/100.00*(double)j);
//           l++;
//        }
//    }
//}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //pre();
    int tt;
    double esp=0.00001;
    cin>>tt;
    while(tt--)
    {
        //cout<<round(1.5)<<endl;
        ll n,p;
        cin>>n>>p;
        map<ll,ll>check;
        ll sum=(n*(n+1LL))/2LL;
        ll left=p/sum;
        ll baki=p%sum;
        if(baki==0)cout<<left<<endl;
        else
        {
            double low=0;
            double high=1;
            while(low<high)
            {
                double mid=(low+high)/2.00;
                ll sum=0;
                for(int i=1; i<=n; i++)
                {
                    sum+=floor((double)i*mid);
                }
                if(sum==baki)break;
                else if(sum<baki)
                {
                    low=mid+esp;
                }
                else
                {
                    high=mid-esp;
                }
            }
            ///cout<<low<<" "<<high<<endl;
            if(low<high)cout<<left<<endl;
            else cout<<-1<<endl;
        }
    }
}

