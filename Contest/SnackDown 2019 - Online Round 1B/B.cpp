#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int main()
{
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n,k;
		cin>>n>>k;
		int c=0;
		long long sum1=0,sum2=0;
		for(int i=0; i<n; i++)
		{
		 cin>>arr[i];
		 if(arr[i]>1)c++;
		}
		if(c<=k)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
