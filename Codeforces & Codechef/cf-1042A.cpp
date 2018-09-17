#include<bits/stdc++.h>
using namespace std;
int arr[100001];
int main()
{
    int n,m;
    cin>>n>>m;
    int mn=1e9;
    int mx=0;
    int sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    sum+=m;
    mx=*max_element(arr,arr+n);
    mn=(sum)/n+((sum%n)?1:0);
    if(mn<mx)mn=mx;
    mx+=m;
    cout<<mn<<" "<<mx<<endl;

}

