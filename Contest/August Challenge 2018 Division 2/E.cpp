#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[100001];
ll brr[100001];
vector<pair<ll,ll> >v;
inline void fastIn(ll &num) {          // Fast IO, with space and new line ignoring
    bool neg = false;
    register ll c;
    num = 0;
    c = getchar();
    for( ; c != '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-') {
        neg = true;
        c = getchar();
    }
    for(; (c>47 && c<58); c=getchar())
        num = (num<<1) + (num<<3) + c - 48;
    if(neg)
        num *= -1;
}
ll tree[4*100001];
void build(ll idx,ll l,ll r)
{
    if(l==r)
    {
        tree[idx]=0;
        return;
    }
    ll lft=2*idx;
    ll rgt=2*idx+1;
    ll mid=(l+r)/2;
    build(lft,l,mid);
    build(rgt,mid+1,r);
    //tree[idx]=min(tree[lft],tree[rgt]);
    tree[idx]=max(tree[lft],tree[rgt]);
}
void update(ll idx,ll l,ll r,ll pos,ll val)
{
    if(l==pos && r==pos)
    {
        tree[idx]=val;
        return;
    }
    ll lft=2*idx;
    ll rgt=2*idx+1;
    ll mid=(l+r)/2;
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
ll Query(ll idx,ll l,ll r,ll s,ll e)
{
    if(l==s && r==e)
    {
        return tree[idx];
    }
    ll lft=2*idx;
    ll rgt=2*idx+1;
    ll mid=(l+r)/2;
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
        ll q1=Query(lft,l,mid,s,mid);
        ll q2=Query(rgt,mid+1,r,mid+1,e);
        //return min(q1,q2);
        return max(q1,q2);
    }
}
ll n,s;
bool cmp(pair<ll,ll>p1,pair<ll,ll>p2)
{
    //cout<<p1.first<<" "<<p2.first<<endl;
    if(p1.first==p2.first)
    {
        return p1.second>p2.second;
    }
    else
    {
        return p1.first<p2.first;
    }
}
struct node
{
    ll fi,se,id;
}vv[100001];
bool cmp1(node p1,node p2)
{
    //cout<<p1.first<<" "<<p2.first<<endl;
    if(p1.fi==p2.fi)
    {
        return p1.se<p2.se;
    }
    else
    {
        return p1.fi<p2.fi;
    }
}
ll check(ll mid,ll n)
{
    ll sum=0;
    ll k=mid;
    build(1,1,n);
    for(int p=1; p<=n; p++)
    {
        ll val=vv[p].fi;
        ll idx=vv[p].id;
        ll l=max(1LL,idx-k);
        ll r=min(n,idx+k);
        ll val_prev=vv[p-1].fi;
        ll idx_prev=vv[p-1].id;
        ll mx=Query(1,1,n,l,r);
        if(l<=idx_prev && idx_prev<=r)
        {
            if(val_prev==val)mx=mx;
            else
            {
                if(mx+1==val_prev)mx=mx+2;
                else mx++;
            }
        }
        else mx++;
        mx=max(1LL,min(mx,n));
        //cout<<mx<<endl;
        update(1,1,n,idx,mx);
        sum+=mx;
    }

    return sum;
}
int lesstha(int l,int r,int val,int t)
{
    int c=0;
    for(int i=l; i<=r; i++)
    {
        if(t==1)
        {
            if(arr[i]<=val)c++;
        }
        else
        {
            if(brr[i]<=val)c++;
        }
    }
    return c;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	ll tt;
	scanf("%lld",&tt);
	while(tt--)
	{
	    v.clear();

        scanf("%lld %lld",&n,&s);
        if(n==0)
        {
            printf("1\n");
            continue;
        }

        build(1,1,n);
	    memset(brr,0,sizeof brr);
	    memset(arr,0,sizeof arr);
        map<ll,ll>mp;
        for(ll i=1; i<=n; i++)
		{
			scanf("%lld",&arr[i]);
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
		ll last=v[0].second;
		vv[1].fi=v[0].first;
		vv[1].se=v[0].second;
		vv[1].id=v[0].second;
		for(int i=1; i<v.size(); i++)
        {
            if(v[i].first>=v[i-1].first)
            {
               vv[i+1].fi=v[i].first;
               vv[i+1].se=abs(v[i].second-last);
               vv[i+1].id=v[i].second;
            }
            else
            {
                vv[i+1].fi=v[i].first;
                vv[i+1].se=abs(v[i].second-last);
                vv[i+1].id=v[i].second;
                last=v[i].second;
            }
        }
        sort(vv+1,vv+1+n,cmp1);
		//memset(arr,0,sizeof arr);
//		for(int i=1; i<=n; i++)
//        {
//            cout<<vv[i].fi<<" "<<vv[i].se<<" "<<vv[i].id<<endl;
//        }
//        cout<<endl;
		ll c=0;
		if(s<n)c=0;
		else{
		ll low=1;
		ll high=n;
		while(low<=high)
		{
		    ll mid=(low+high)/2;
		    //cout<<low<<" "<<high<<" "<<mid<<" "<<check(mid,n)<<endl;
		    //cout<<low<<" "<<high<<endl;
		    ll sum=check(mid,n);
		    if(sum<=s)
            {
                c=mid;
                low=mid+1;
            }
            else high=mid-1;
            //system("pause");
		}
		if(n<=s)c++;
		}
		printf("%lld\n",c);

        for(ll i=1; i<=n; i++)
        {
            c=check(i,n);
            cout<<i<<": ====>\n";
            for(ll j=1; j<=n; j++)cout<<Query(1,1,n,j,j)<<" ";
            cout<<endl;
        }
//            for(ll j=1; j<=n; j++)
//            {
//                int l=max(1LL,j-i);
//                int r=min(n,i+j);
//                int v1=lesstha(l,r,brr[j],2);
//                int v2=lesstha(l,r,arr[j],1);
//                if(v1!=v2)
//                {
//                    cout<<i<<" "<<j<<" "<<arr[j]<<" "<<brr[j]<<" "<<v1<<" "<<v2<<endl;
//                    int c1=0;
//                    for(int ii=j-i; ii<=j+i; ii++){cout<<arr[ii]<<" ";c1++;}
//                    cout<<"==>"<<c1<<endl;
//                    c1=0;
//                    for(int ii=j-i; ii<=j+i; ii++){c1++;cout<<brr[ii]<<" ";}
//                    cout<<"==>"<<c1<<endl;
//                    return 0;
//                }
//            }
//            for(ll j=1; j<=n; j++)
//            {
//                int l=max(1LL,j-i);
//                int r=min(n,i+j);
//                cout<<lesstha(l,r,arr[j],1)<<" ";
//            }
//            cout<<endl;
//            for(ll j=1; j<=n; j++)
//            {
//                int l=max(1LL,j-i);
//                int r=min(n,i+j);
//                cout<<lesstha(l,r,brr[j],2)<<" ";
//            }
//            cout<<"==> "<<c<<endl;
//        }

	}
}
