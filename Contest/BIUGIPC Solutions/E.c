#include<stdio.h>
#include<math.h>

const double pi = acos(-1);
double radtodeg(double rad){return rad * (180.0/pi);}
double degtorad(double ang){return ang * (pi/180.0);}

double sector(double r, double ang){
       double a = (ang * pi / 360.0);
       a = a - (0.5 * sin(degtorad(ang)) );
       return a * r * r;
 }

int main(){

    int tk,cs = 0;
    scanf("%d",&tk);
    while(tk--){
        double r1,r2,x1,y1,x2,y2;
        scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&r1,&x2,&y2,&r2);
        double d = sqrt((fabs(x2-x1) * fabs(x2-x1)) + (fabs(y2-y1) * fabs(y2-y1)));
        if (d>=r1+r2){
            printf("%.6lf\n",(pi*r1*r1) + (pi*r2*r2) );
            continue;
        }
        if(d<=fabs(r1-r2)){
            printf("%.6lf\n",fabs((pi*r1*r1) - (pi*r2*r2)));
            continue;
        }
       double area = 0.0;
       // 1st circle sector area
       double ang = acos((r1 * r1 + d * d - r2 * r2) / (2.0 * r1 * d));
       ang = 2 *radtodeg(ang);
       area += sector(r1,ang);
       // 2nd circle sector area
       ang =  acos((r2 * r2 + d * d - r1 * r1) / (2.0 * r2 * d));
       ang = 2 * radtodeg(ang);
       area += sector(r2,ang);
       printf("%.6lf\n",((pi*r1*r1) +(pi*r2*r2)) - area);
    }

  return 0;

}


