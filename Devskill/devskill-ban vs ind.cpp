#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int val;
        double p;
        cin>>val>>p;
        val--;
        double sum=0;
        while(val--)
        {
            sum+=powl(p,val);
        }
        cout<<1.00-sum<<endl;
    }
}
