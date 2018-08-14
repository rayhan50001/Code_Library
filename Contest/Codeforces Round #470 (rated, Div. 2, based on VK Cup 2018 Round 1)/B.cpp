#include<bits/stdc++.h>
using namespace std;
#define MAX 1000009
bool v[MAX];
int len, sp[MAX];

void Sieve(){
	for (int i = 2; i < MAX; i += 2)	sp[i] = 2;//even numbers have smallest prime factor 2
	for (int i = 3; i < MAX; i += 2){
		if (!v[i]){
			sp[i] = i;
			for (int j = i; (j*i) < MAX; j += 2){
				if (!v[j*i])	v[j*i] = true, sp[j*i] = i;
			}
		}
	}
}
set <int> factorize(int k) {
	set <int> ans;
	while(k>1) {
		ans.insert(sp[k]);
		k/=sp[k];
	}
	return ans;
}
int main()
{
    Sieve();
    int x2;
    cin>>x2;
    while(true)
    {
        set<int>fact=factorize(n);
        for(auto it:fact)cout<<it<<" ";
        cout<<endl;
        system("pause");
    }
}
