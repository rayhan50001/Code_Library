#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll can_buy(ll taka)
{
    if(taka<3)return 0;
    ll left=taka%5;
    ll total=(taka/5)*2;
    if(left>=3)total++;
    return total;
}
int main()
{
    ll n,k,p;
    while(cin>>n>>k>>p && n && k && p)
    {
        ll pan_moshla=can_buy(n);
        ll khaite_parbe=pan_moshla/p;
        ll thakbe=pan_moshla%p;
        ll solved=khaite_parbe*k;
        printf("Emrul solves %lld Problems, saves %lld Pan Moshlas\n",solved,thakbe);
    }
}
