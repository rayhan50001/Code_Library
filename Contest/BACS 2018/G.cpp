#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,k;
        cin>>n>>k;
        string s="";
        for(int i=1; i<=n; i++)
        {
            s+=char(i+'0');
        }
        vector<string>v;
        do
        {
            int paisi=0;
            for(int i=1; i<=n; i++)
            {
               if((s[i-1]-'0')==i)
               {
                   paisi=1;
                   break;
               }
            }
            if(paisi==0)
            {
                v.push_back(s);
            }
        }while(next_permutation(s.begin(),s.end()));
        sort(v.begin(),v.end());
        cout<<v[k-1][0];
        for(int i=1; i<n; i++)
        {
            cout<<" "<<v[k-1][i];
        }
        cout<<endl;
    }
}
