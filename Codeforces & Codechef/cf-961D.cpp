#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll> >v;
ll vis[100001];
ll n;
ll colinear(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3)
{
    if((x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2))==0)return 1;
    else return 0;
}
ll solve(ll x1,ll y1,ll x2,ll y2)
{
    //cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
    memset(vis,0,sizeof vis);
    ll xx1=-INT_MAX,xx2=-INT_MAX,yy1=-INT_MAX,yy2=-INT_MAX;
    for(int i=0; i<n; i++)
    {
        ll x3=v[i].first;
        ll y3=v[i].second;
        if(colinear(x1,y1,x2,y2,x3,y3)==1)
        {
            //cout<<x3<<" "<<y3<<endl;
            vis[i]=1;
        }
        else
        {
            if(xx1==-INT_MAX && yy1==-INT_MAX)
            {
                xx1=x3;
                yy1=y3;
            }
            else if(xx2==-INT_MAX && yy2==-INT_MAX)
            {
                xx2=x3;
                yy2=y3;
            }
        }
    }
    if(xx1==-INT_MAX || xx2==-INT_MAX || yy1==-INT_MAX || yy2==-INT_MAX)return 1;
    x1=xx1;
    y1=yy1;
    x2=xx2;
    y2=yy2;
    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            ll x3=v[i].first;
            ll y3=v[i].second;
            //cout<<x3<<" "<<y3<<endl;

            if(colinear(x1,y1,x2,y2,x3,y3)==0)
            {
                //cout<<endl<<endl;
                return 0;
            }
        }
    }

    return 1;
}
int main()
{
    cin>>n;
    for(ll i=0; i<n; i++)
    {
        ll x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    if(n<=4)cout<<"YES\n";
    else
    {
        if(solve(v[0].first,v[0].second,v[1].first,v[1].second))cout<<"YES\n";
        else if(solve(v[0].first,v[0].second,v[2].first,v[2].second))cout<<"YES\n";
        else if(solve(v[1].first,v[1].second,v[2].first,v[2].second))cout<<"YES\n";
        else cout<<"NO\n";
    }
}
