#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[100001];
ll brr[100001];
vector<pair<ll,ll> >v;
ll tree[3*100001];
void build(int idx,int l,int r)
{
    if(l==r)
    {
        tree[idx]=0;
        return;
    }
    int lft=2*idx;
    int rgt=2*idx+1;
    int mid=(l+r)/2;
    build(lft,l,mid);
    build(rgt,mid+1,r);
    //tree[idx]=min(tree[lft],tree[rgt]);
    tree[idx]=max(tree[lft],tree[rgt]);
}
void update(int idx,int l,int r,int pos,int val)
{
    if(l==pos && r==pos)
    {
        tree[idx]=val;
        return;
    }
    int lft=2*idx;
    int rgt=2*idx+1;
    int mid=(l+r)/2;
    if(pos<=mid)
    {
        update(lft,l,mid,pos,val);
    }
    else
    {
        update(rgt,mid+1,r,pos,val);
    }
    //tree[idx]=min(tree[lft],tree[rgt]);
    tree[idx]=max(tree[lft],tree[rgt]);
}
int Query(int idx,int l,int r,int s,int e)
{
    if(l==s && r==e)
    {
        return tree[idx];
    }
    int lft=2*idx;
    int rgt=2*idx+1;
    int mid=(l+r)/2;
    if(e<=mid)
    {
        Query(lft,l,mid,s,e);
    }
    else if(s>mid)
    {
        Query(rgt,mid+1,r,s,e);
    }
    else
    {
        int q1=Query(lft,l,mid,s,mid);
        int q2=Query(rgt,mid+1,r,mid+1,e);
        //return min(q1,q2);
        return max(q1,q2);
    }
}
bool cmp(pair<ll,ll>p1,pair<ll,ll>p2)
{
    if(p1.first==p2.first)
    {
        return p1.second>p2.second;
    }
    else return p1.first<p2.first;
}
//ll lessthan(ll l,ll r,ll x,int idx)
//{
//	ll mx=0;
//	ll c=0;
//	for(ll i=l; i<=r; i++)
//	{
//	    if(idx!=i)
//	    {
//	        //cout<<arr[i]<<" ";
//            if(arr[i]<=x)
//            {
//                mx=max(mx,arr[i]);
//            }
//	    }
//	}
//	return mx;
//}
ll check(ll mid,ll n)
{
    ll sum=0;
    ll k=mid;
    build(1,1,n);
    for(ll p=0; p<n; p++)
    {
        ll val=v[p].first;
        ll idx=v[p].second;
        ll l=max(1LL,idx-k);
        ll r=min(n,idx+k);
//        //arr[idx]=val;
//        for(int i=1; i<=n; i++)cout<<arr[i]<<" ";
//        cout<<endl;
        ll mx1=0,mx2=0;
        if(idx-1<=0)
        {

        }
        else
        {
            mx1=Query(1,1,n,l,idx-1);
        }
        //cout<<1<<"==>"<<lll<<" "<<rrr<<"..... 2 ";
        if(idx+1>n)
        {

        }
        else
        {
            mx2=Query(1,1,n,idx+1,r);
        }
        //ll mx=lessthan(l,r,val,idx);
        //cout<<l<<" "<<r<<" "<<mx<<endl;
        //cout<<mx1<<" "<<mx2<<endl;
        ll mx=max(mx2,mx1);
        if(v[p-1].first==val)
        {
            if(v[p-1].second>=l && v[p-1].second<=r)mx=mx;
            else mx++;
        }
        else mx++;
        //cout<<mx<<endl;
        update(1,1,n,idx,mx);
        sum+=mx;
    }
    return sum;
}
int main()
{
	ll tt;
	cin>>tt;
	while(tt--)
	{
	    v.clear();
        ll n,s;
        cin>>n>>s;
        map<ll,ll>mp;
        for(ll i=1; i<=n; i++)
		{
			cin>>arr[i];
			brr[i]=arr[i];
		}
		sort(brr+1,brr+n+1);
		ll l=1;
		for(ll i=1; i<=n; i++)
		{
			if(mp[brr[i]])continue;
			mp[brr[i]]=l;
			l++;
		}
		for(ll i=1; i<=n; i++)
		{
			arr[i]=mp[arr[i]];
			v.push_back({arr[i],i});
		}
		sort(v.begin(),v.end(),cmp);
//		for(int i=0; i<v.size(); i++)
//        {
//            cout<<v[i].first<<" "<<v[i].second<<endl;
//        }
//        cout<<endl;
		ll c=0;
		int low=0;
		int high=n;
		while(low<high)
		{
		    int mid=(low+high)/2;
		    cout<<low<<" "<<high<<endl;
		    if(check(mid,n)<=s)
            {
                low=mid+1;
                c=mid+1;
            }
            else high=mid-1;
		}
		cout<<c<<endl;
	}
}
