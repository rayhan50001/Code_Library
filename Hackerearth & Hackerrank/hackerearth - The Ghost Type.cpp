//bitmask dp
#include<bits/stdc++.h>
#define setbit(mask,i) mask|=(1<<i) // mask = 1010 i=2 then mask = 1110
#define unsetbit(mask,i) mask&!(1<<i) // mask = 1010 i=3 then mask = 0010
#define checkbit(mask,i) mask&(1<<i) // mask = 1010 i=3 then mask = 1000
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
#define pb push_back
vector<int>submask[22];
bool vis[1<<22];
ll dp[1<<22];
int N;
ll rec(int mask){
    if(mask==(1<<(N+1))-2) return 1;
    if(vis[mask]) return dp[mask];
    vis[mask] = 1;
    ll &ret = dp[mask];
    ret=0;
    int x;
    cout<<mask<<endl;
    system("pause");
    for(int i=1;i<=N;i++){
        if(!(mask&(1<<i))){
            bool ok = 1;
            rep(j,submask[i].size()){
                x = submask[i][j];
                if(!(mask&(1 << x ))) ok=0;
            }
            if(ok){
                cout<<i<<" yes\n";
                ret += rec(mask|(1<<i));
            }
        }
    }
    return ret;
}
int main()
{
    for(int i=1;i<=20;i++){
        for(int j=i-1;j>=1;j--){
            if( (i&j)==j ) submask[i].pb(j);
        }
    }
    cin >> N;
    for(int i=1; i<=N; i++)
    {
        cout<<i<<" : ";
        for(int j=0; j<submask[i].size(); i++)cout<<submask[i][j]<<" ";
        cout<<endl;
    }
    cout<<rec(0);
}
