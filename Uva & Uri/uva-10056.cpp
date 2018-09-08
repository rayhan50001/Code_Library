#include<bits/stdc++.h>
using namespace std;
double win[100001];
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        double sum=0.0;
        int id;
        double p;
        cin>>n>>p>>id;
        win[1]=p;
        sum=p;
        for(int i=2; i<=n; i++)
        {
            win[i]=win[i-1]*(1.00-p)*1.00;
            sum+=win[i];
        }
        if(sum==0)printf("0.0000\n");
        else printf("%.4f\n",win[id]/sum);
    }
}
