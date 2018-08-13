#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> v[100001];
inline void fastIn(ll &num)            // Fast IO, with space and new line ignoring
{
    bool neg = false;
    register int c;
    num = 0;
    c = getchar();
    for( ; c != '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-')
    {
        neg = true;
        c = getchar();
    }
    for(; (c>47 && c<58); c=getchar())
        num = (num<<1) + (num<<3) + c - 48;
    if(neg)
        num *= -1;
}
int main ()
{
    ll tt;
    fastIn(tt);
    while(tt--)
    {
        ll n,a0,b,c;
        fastIn(n);
        fastIn(a0);
        fastIn(b);
        fastIn(c);
        v[a0].push_back(0);
        for(ll i=1; i<n; i++)
        {
            a0=(a0*b+c)%n;
            v[a0].push_back(i);
        }
        ll sorted=0;
        ll ans=0;
        for(int i=0; i<n; i++)
        {
            for(ll j=0; j<v[i].size(); j++)
            {
                ans+=abs(v[i][j]-sorted);
                sorted++;
            }
            v[i].clear();
        }
        printf("%lld\n",ans);
    }
    return 0;
}
