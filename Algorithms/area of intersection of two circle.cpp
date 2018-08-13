//INTERSECTECTION AREA & COMMON AREA & UNCOMMON AREA

#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define ll double
int main()
{
    //freopen("out.txt","w",stdout);
    int tt,kk=1;
    cin>>tt;
    while(tt--)
    {
        ll x1,y1,r1,x2,y2,r2,d,ans=0.0,r1sqr,r2sqr,dsquare;
        cin>> x1>>y1>>r1>>x2>>y2>>r2;
        r1sqr=r1*r1; r2sqr=r2*r2;
        d=sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)  );
        dsquare=d*d;
        if( d> r1+r2 ) ans=0;
        else if( d<abs(r2-r1) && r1>=r2  ) ans= pi*r1sqr-pi*r2sqr;
        else if( d<abs(r2-r1) && r1<=r2  ) ans= pi*r2sqr-pi*r1sqr;
        else
        {
            ll phi= (acos((r1sqr+dsquare-r2sqr )/(2*r1*d)))*2;
            ll theta= (acos((r2sqr+dsquare-r1sqr )/(2*r2*d)))*2;
            ll area1= 0.5*theta*r2sqr -0.5*r2sqr*sin(theta);
            ll area2=0.5*phi*r1sqr-0.5*r1sqr*sin(phi);
            ans= area1 + area2;
            double total_area=(pi*r1*r1)+(pi*r2*r2);
            //cout<<total_area<<" "<<ans<<endl;
            ans=total_area-ans;
        }
        if(ans-0.0000000<0.000000001)
        {
            double total_area=(pi*r1*r1)+(pi*r2*r2);
            //cout<<total_area<<endl;
            ans=total_area-ans;
        }
        printf("%.6f\n",ans);
    }
}
