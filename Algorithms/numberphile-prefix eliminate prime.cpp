#include <bits/stdc++.h>
using namespace std;
bool isprime(int n)
{
    if(n<=1)return 0;
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0)return 0;
    }
    return 1;
}
set<int>goodprime;
void recur(int n)
{
    if(n>1000000000)return;
    if(isprime(n)==0)return;
    for(int i=1; i<=9; i++)
    {
        goodprime.insert(n);
        int val=log10(n);
        int next=i*powl(10,val+1)+n;
        //cout<<val<<" "<<next<<" ";
        //system("pause");
        if(isprime(next))recur(next);
    }
    return;
}
int main()
{
    recur(2);
    recur(3);
    recur(5);
    recur(7);
    cout<<goodprime.size()<<endl;
    for(auto it: goodprime)
    cout<<endl;
    return 0;
}
