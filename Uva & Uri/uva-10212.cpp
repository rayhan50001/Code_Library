//NpR=N!/(N-R)! R<=N
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 10
vector<ll>prime;
ll pr[20000001];
void seive()
{
    pr[1]=1;
    for(int i=2; i*i<=20000000; i++)
    {
        if(pr[i]==0)
        {
            for(int j=i*i; j<=20000000; j+=i)
            {
                pr[j]=1;
            }
        }
    }
    prime.push_back(2);
    for(int i=1; i<=20000000; i+=2)
    {
        if(pr[i]==0)
        {
            prime.push_back(i);
        }
    }
}
ll addMod(ll a, ll b, ll m)
{
    if (a + b < 0)
        return (a - m) + b;
    else if (a + b >= m)
        return a + b - m;
    else
        return a + b;
}
ll multiplyMod(ll a, ll b, ll m)
{
    if (b == 0 || a <=LLONG_MAX / b)
        return (a * b) % m;
    ll result = 0;
    if (a > b) swap(a,b);
    while (a > 0)
    {
        if ((a & 1) != 0)
        {
            result = addMod(result, b, m);
        }
        a >>= 1;
        b -= m - b;
        if (b < 0)
            b += m;
    }
    return result;
}
ll bigMod(ll b,ll p,ll m)
{
    ll x=1,y=b%m;
   while(p>0)
   {
       if(p%2==1)
       {
           x=multiplyMod(x,y,m);
       }
       y=multiplyMod(y,y,m);
       p=p/2LL;
   }
   return x;
}
map<ll,int>mp;
void factor(ll n,int type)
{
      int len=prime.size();
      ll ans=1;
      for(int i=0; prime[i]<=n && i<len; i++)
      {
          ll nn=n;
          ll c=0;
          while(nn>0)
          {
          nn/=prime[i];
          c+=nn;
          //cout<<nn<<endl;
          }
          if(type==1)
            mp[prime[i]]=c;
          if(type==2)
          {
              if(mp[prime[i]])mp[prime[i]]=mp[prime[i]]-c;
          }
      }
}
int main()
{
    //freopen("out.txt","w",stdout);
//    seive();
    ll n,r;
    while(scanf("%lld %lld",&n,&r)==2)
    {
        ll len=n-r+1;
        ll ans=1;
        int c2=0,c5=0;
        for(ll i=len; i<=n; i++)
        {
            ll n=i;
            while (n % 2 == 0)
            {
                c2++;
                n /= 2;
            }
            while (n % 5 == 0)
            {
                c5++;
                n /= 5;
            }
            ans=(ans%MOD*n%MOD)%MOD;
        }
        ll mn=min(c2,c5);
        ans=(ans%MOD*bigMod(2LL,c2-mn,MOD))%MOD;
        ans=(ans%MOD*bigMod(5LL,c5-mn,MOD))%MOD;
        printf("%lld\n",ans);
    }
}
