#include<bits/stdc++.h>
using namespace std;
vector<int>prime;
int pr[100001];
void pre()
{
    pr[0]=pr[1]=1;
    for(int i=2; i*i<=10001; i++)
    {
        if(pr[i]==0)
        {
            for(int j=i+i; j<=10001; j+=i)pr[j]=1;
        }
    }
    for(int i=1; i<=10001; i++)
    {
        if(!pr[i])prime.push_back(i);
    }
}
int main()
{
    pre();
    int tt,kk=1;
    cin>>tt;
    while(tt--)
    {
    int n;
    cin>>n;
    printf("Caso %d ->",kk++);
    int val=prime[n-1];
    val++;
    for(int i=0; i<prime.size(); i++)
    {
        if(prime[i]<=val)
        {
        printf(" %d",prime[i]);
        }
        else break;
    }
    cout<<endl;
    }
}

