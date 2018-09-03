#include<bits/stdc++.h>
using namespace std;
#define ll long long
bitset<10000000>isPrime;
vector<long long>primes;
void sieveGen(long long N) {
    isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for(long long i = 2; i <= N; i++) {		//Note, N isn't square rooted!
		if(isPrime[i]) {
			for(long long j = i*i; j <= N; j+= i)
                isPrime[j] = 0;
			primes.push_back(i);
}}}

vector<pair<ll, ll> > primeFactor(ll n) {
    vector<pair<ll, ll> >factor;
	for(long long i = 0; i < (int)primes.size() && primes[i] <= n; i++) {
        bool first = 1;
		while(n%primes[i] == 0) {
            if(first) {
                factor.push_back({primes[i], 0});
                first = 0;
            }
			factor.back().second++;
			n/=primes[i];
	}}
	return factor;
}
int main()
{
    sieveGen(1000000);
    ll n;
    cin>>n;
    //ll l,r;
    //cin>>l>>r;
    //for(int i=l; i<=r; i++){
    //ll n=i;
    vector<pair<ll,ll> >factor=primeFactor(n);
    int yes=0;
    for(int i=0; i<factor.size(); i++)
    {
        if(n%(factor[i].first*factor[i].first)==0)
        {
            yes=1;
            break;
        }
    }
    if(yes)cout<<"True, "<<n<<" is a lab number\n";
    //}
    else cout<<"False, "<<n<<" is not a lab number\n";
}
