#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll lcs[35][35];
ll way[35][35];
int LCS(string a,string b)
{
    memset(lcs,0LL,sizeof lcs);
    for(int i=0; i<=a.size(); i++)
    {
        for(int j=0; j<=b.size(); j++)
        {
            if(i==0 || j==0)lcs[i][j]=0;
            else if(a[i-1]==b[j-1])
            {
                lcs[i][j]=1+lcs[i-1][j-1];
            }
            else
            {
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    return lcs[a.size()][b.size()];
}
void combination(string a,string b)
{
    memset(way,0LL,sizeof way);
    for(int i=0; i<=a.size(); i++)
    {
        way[i][0]=1;
    }
    for(int i=0; i<=b.size(); i++)
    {
        way[0][i]=1;
    }
    for(int i=1; i<=a.size(); i++)
    {
        for(int j=1; j<=b.size(); j++)
        {
            if(a[i-1]==b[j-1])
            {
                way[i][j]+=way[i-1][j-1];
            }
            else
            {
                if(lcs[i][j]==lcs[i][j-1])
                {
                    way[i][j]+=way[i][j-1];
                }
                if(lcs[i][j]==lcs[i-1][j])
                {
                    way[i][j]+=way[i-1][j];
                }
            }
        }
    }
}
int main()
{
    int tt,kk=1;
    cin>>tt;
    while(tt--)
    {
        string a,b;
        cin>>a>>b;
        int len=a.size()+b.size()-LCS(a,b);
        combination(a,b);
        printf("Case %d: %d %lld\n",kk++,len,way[a.size()][b.size()]);
    }
}
