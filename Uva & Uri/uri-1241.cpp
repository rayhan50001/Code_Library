#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        string a,b;
        cin>>a>>b;
        if(a.size()<b.size())cout<<"nao encaixa\n";
        else
        {
            int start=a.size()-b.size();
            int fit=0;
            for(int i=start; i<a.size(); i++)
            {
                if(a[i]!=b[fit])break;
                fit++;
            }
            if(fit==b.size())cout<<"encaixa\n";
            else cout<<"nao encaixa\n";
        }
    }
}
