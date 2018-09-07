#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<=2)cout<<"No\n";
    else
    {
        cout<<"Yes\n";
        cout<<n-1<<" ";
        for(int i=1; i<=n-1; i++)cout<<i<<" ";
        cout<<endl;
        cout<<1<<" "<<n<<endl;
    }
}

