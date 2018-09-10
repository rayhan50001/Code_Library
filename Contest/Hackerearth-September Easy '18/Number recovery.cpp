#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1000001];
ll brr[1000001];
vector<int>v[1000001];
int main()
{
    int n,q;
    cin>>n>>q;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i]>>brr[i];
    }
    while(q--)
    {
        int t,i;
        cin>>t>>i;
        if(t==1)
        {
            vector<int>vv=v[i];
            int paisi=0;
            for(int i=0; i<vv.size(); i++)if(vv[i]==t)paisi=1;
            if(paisi==1)cout<<0<<endl;
            else
            {
            ll a=arr[i];
            ll d=brr[i];
            ll first=a-d;
            ll second=a+d;
            if(first>0 && second>0 && first!=second)cout<<2<<" "<<first<<" "<<second;
            else if(first>0)cout<<1<<" "<<first;
            else if(second>0)cout<<1<<" "<<second;
            else {cout<<0;continue;}
            v[i].push_back(1);
            }
        }
        else if(t==2)
        {
            vector<int>vv=v[i];
            int paisi=0;
            for(int i=0; i<vv.size(); i++)if(vv[i]==t)paisi=1;
            if(paisi==1)cout<<0<<endl;
            else
            {
                cout<<"-1";
                v[i].push_back(2);
            }
        }
        else if(t==3)
        {
            vector<int>vv=v[i];
            int paisi=0;
            for(int i=0; i<vv.size(); i++)if(vv[i]==1|| vv[i]==2)paisi++;
            if(paisi>=2)cout<<0<<endl;
            else if(paisi==1)
            {
                int p=0;
                for(int i=0; i<vv.size(); i++)if(vv[i]==1)p=1;
                if(p==1)
                {
                    cout<<"-1";
                    v[i].push_back(2);
                }
                else
                {
                    ll a=arr[i];
                    ll d=brr[i];
                    ll first=a-d;
                    ll second=a+d;
                    if(first>0 && second>0 && first!=second)cout<<2<<" "<<first<<" "<<second;
                    else if(first>0)cout<<1<<" "<<first;
                    else if(second>0)cout<<1<<" "<<second;
                    else {cout<<0;continue;}
                    v[i].push_back(1);
                }
            }
            else
            {
            ll a=arr[i];
            ll d=brr[i];
            ll first=a-d;
            ll second=a+d;
            if(first>0 && second>0 && first!=second)cout<<2<<" "<<first<<" "<<second;
            else if(first>0)cout<<1<<" "<<first;
            else if(second>0)cout<<1<<" "<<second;
            else {cout<<0;continue;}
            v[i].push_back(1);
            }
        }
        cout<<endl;
    }
}
