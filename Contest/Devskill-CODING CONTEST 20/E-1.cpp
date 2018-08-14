#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define s second
#define f first

typedef long long ll;
typedef long double ld;

using namespace std;

const ll N = 200000000;

bitset<N/15+10> b;
vector<int> primes;
vector<int> ans;

int main()
{
    ans.reserve(26825909);
    ll M = N/15+10;
    b.set();
    b[0] = 0;
    b[1] = 0;
    for(ll i=2;i<=M;i++){
        if(b[i]){
            for(ll j=i*i;j<=M;j+=i)
                b[j] = 0;
            if(i != 2) primes.pb(i);
        }
    }
    int sz = primes.size();
    for(int i=0;i<sz;i++){
        for(int j=i+1;j<sz && (ll)primes[i]*primes[j] <= N;j++){
            for(int k=j+1;k<sz && (ll)primes[i]*primes[j]*primes[k] <= N;k++){
                ans.pb(primes[k]*primes[i]*primes[j]);
            }
        }
    }
    sort(ans.begin(),ans.end());
    int T;
    scanf("%d",&T);
    int x = 1;
    while(T--){
        int l,r;
        scanf("%d %d",&l,&r);
        int res = upper_bound(ans.begin(),ans.end(),r) - upper_bound(ans.begin(),ans.end(),l-1);
        printf("Case %d: %d\n",x,res);
        x++;
    }
    return 0;
}
