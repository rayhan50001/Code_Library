
#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T>inline string tostring(T a)
{
    ostringstream os("");
    os << a;
    return os.str();
}
ll dp[20];
void pre()
{
    dp[1]=9;
    dp[2]=9;
    for(int i=3; i<=19; i++)
    {
        dp[i]=dp[i-1]*10LL;
        //cout<<dp[i]<<endl;
    }
    dp[0]=0;
    for(int i=1; i<=18; i++)dp[i]+=dp[i-1];
}
long long calc(long long n)
{
    string s=tostring(n);
    long long res=dp[s.size()-1];
    //cout<<endl<<endl;
    for(int i=1; i<=9; i++)
    {
        //cout<<i<<"==" ;
        if(s[0]-'0'<i)break;
        if(s[0]-'0'==i)
        {
            long long val=0;
            for(int j=1; j<s.size()-1; j++)val=val*10+s[j]-'0';
            val++;
            //cout<<val<<endl;
            if(s[s.size()-1]-'0'<i)val--;
            res+=val;
        }
        else
        {
            int len=s.size();
            //cout<<powl(10,max(0,len-2))<<endl;
            res+=powl(10,max(0,len-2));
        }
    }
    return res;
}
int main()
{
   pre();
   long long l,r;
   cin>>l>>r;
   long long high=calc(r);
   long long low=calc(l-1);
   cout<<high-low<<endl;
}
