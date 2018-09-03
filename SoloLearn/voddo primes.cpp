#include<bits/stdc++.h>
using namespace std;
bitset<1000009>isPrime;
vector<int>primes;
void sieveGen(int N)
{
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for(long long i = 2; i <= N; i++)
    {
        if(isPrime[i])
        {
            for(long long j = i*i; j <= N; j+= i)
                isPrime[j] = 0;
            primes.push_back((int)i);
        }
    }
}
template<typename T>inline string tostring(T a)
{
    ostringstream os("");
    os << a;
    return os.str();
}
template< class T > inline T _bigmod(T n,T m,T mod)
{
    T ans=1,mult=n%mod;
    while(m)
    {
        if(m & 1) ans=(ans*mult)%mod;
        m>>=1;
        mult=(mult*mult)%mod;
    }
    ans%=mod;
    return ans;
}
string divide(int n,int digit)
{
    int a=1;
    int b=n;
    int c=digit;
    int pc=0;
    string ans;
    int x;
    ans+=tostring(a/b);
    ans+=".";
    a%=b;
    while(pc<c)
    {
        a*=10;
        x=a/b;
        a%=b;
        ans+=tostring(x);
        string rr=tostring(x);
        //if(rr.size()>=2)cout<<"yes\n";
        pc++;
    }
    //cout<<ans<<" ";
    return ans;
}
//for given range
int divisor(int nn)
{
    int n=nn-1;
    int paisi=-1;
    for(int i=1; i*i<=n; i++)
    {
        if(n%i==0)
        {
            if(i!=n/i)
            {
                int v1=i;
                int v2=n/i;
                if(_bigmod(10,v1,nn)==1)return v1;
                if(_bigmod(10,v2,nn)==1)return v2;
            }
            else
            {
                int v2=n/i;
                if(_bigmod(10,v2,nn)==1)return v2;
            }
        }
    }
    return n;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    sieveGen(1000000);
    int l,r;
    cout<<"Voodoo Primes: \n";
    cin>>l>>r;
    int start=lower_bound(primes.begin(),primes.end(),l)-primes.begin();
    int end=upper_bound(primes.begin(),primes.end(),r)-primes.begin();
    for(int i=start; i<=end; i++)
    {
        int n=primes[i];
        int len=divisor(n);
        string res=divide(n,len);//calculate up to 3000 digits for better accuracy
        //cout<<res<<endl;
        string number=tostring(n);
        if(res.find(number)!=string::npos)
        {
            cout<<len<<": ";
            cout<<number<<" ";
            cout<<endl;
        }

    }

}
