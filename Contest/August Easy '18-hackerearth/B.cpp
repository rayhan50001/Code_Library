#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans[100001];
ll arr[100001];
ll freq[31][100001];
int main()
{
    ll n,k;
    cin>>n>>k;
    for (int i = 1; i <= n; ++i) {
		scanf("%lld", &arr[i]);
		for (int j = 0; j < 30; ++j) {
			if (arr[i] & (1 << j)) {
				freq[j][i]++;
				freq[j][min(n + 1, i + k + 1)]--;
			}
		}
	}
	for (int bit = 0; bit < 30; ++bit) {
		int now = 0;
		for (int i = 1; i <= n; ++i) {
			now += freq[bit][i];
			arr[i] |= (now > 0) << bit;
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%lld ", arr[i]);
	}
}
