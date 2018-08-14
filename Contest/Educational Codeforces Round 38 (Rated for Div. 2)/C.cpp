#include<bits/stdc++.h>
using namespace std;
vector<long long>sq;
void pre()
{
    for(long long i=1; i<=100000; i++)
    {
        sq.push_back(i*i);
    }
}
int main()
{
    pre();
    int tt;
    cin>>tt;
    while(tt--)
    {
        long long x;
        cin>>x;
        if(x==0)cout<<"1 1\n";
        else if(x==1 || x==2)cout<<"-1\n";
        else
        {
        long long up=lower_bound(sq.begin(),sq.end(),x)-sq.begin();
        long long val1=sq[up];
        long long next=val1-x;
        //cout<<next<<endl;
        long long lo=lower_bound(sq.begin(),sq.end(),next)-sq.begin();
        long long val2=sq[lo];
        //cout<<val1<<" "<<val2<<endl;
        if((val1-val2)>(x-val1))
        {
            long long ans=val2*sqrt(val2);
            cout<<sqrt(val1)<<" "<<sqrt(val2)<<endl;
        }
        else
        {
            cout<<"-1\n";
        }
        }
    }
}
