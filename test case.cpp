#include<bits/stdc++.h>
using namespace std;
int correct1[201][201];
int correct2[201][201];
void pre(int n,int p)
{
    int l=1;
    for(int i=0; i<n; i++)
    {
        int p=1;
        int q=0;
        for(int j=0; j<n; j++)
        {
            if(l%2==1)
            {
              correct1[i][j]=p%2;
              p++;
            }
            else
            {
               correct1[i][j]=q%2;
               q++;
            }
        }
        l++;
    }
    l=1;
    for(int i=0; i<n; i++)
    {
        int p=0;
        int q=1;
        for(int j=0; j<n; j++)
        {
            if(l%2==1)
            {
              correct2[i][j]=p%2;
              p++;
            }
            else
            {
               correct2[i][j]=q%2;
               q++;
            }
        }
        l++;
    }
    if(p%2==0){
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<correct1[i][j];
        }
        cout<<endl;
    }
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<1;
            }
            cout<<endl;
        }
    }
}
int main()
{
    freopen("in.txt","w",stdout);
    int n;
    n=97;
    cout<<n<<'\n';
    for(int i=0; i<4; i++)
    {
    pre(n,i);
    cout<<'\n';
    }
}
