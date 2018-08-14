#include<bits/stdc++.h>
using namespace std;
int main()
{
    double R,x1,y1,x2,y2;
    cin>>R>>x1>>y1>>x2>>y2;
    double radius=sqrt(powl((x1-x2), 2) + powl((y1-y2), 2)) + R;
    radius/=2;
    double d1=atan((y2-y1)/(x2-x1));
    double x=radius*sin(d1);
    double y=radius*cos(d1);
    x+=1.0;
    y+=1.0;
    printf("%.17f %.17f %.17f\n",x,y,radius);
}
