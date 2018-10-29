#include<bits/stdc++.h>
using namespace std;
bool prime[1000010];

void sieve()
{
    prime[0]=prime[1]=1;
    for(int i=2; i*i<=1000001; i++)
    {
        if(prime[i]==0)
        {
            for(int j=i*i; j<=1000001; j+=i)
            {
                prime[j]=1;
            }
        }
    }
}

int main()
{
    sieve();

    int n;
    scanf("%d",&n);


    int cnt=0;

    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        if(prime[x]==0 || x==1)cnt++;
    }
    int ans=n-cnt;

    printf("%d\n",ans);
}
