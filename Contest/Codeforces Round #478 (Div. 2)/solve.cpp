#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    map<int,int>mp;
    int mx=0;
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        mp[x]++;
        mx=max(mx,x);
    }
    cout<<mp[mx]<<endl;
}
