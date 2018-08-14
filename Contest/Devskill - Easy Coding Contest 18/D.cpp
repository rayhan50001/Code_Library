#include<bits/stdc++.h>
using namespace std;
void palin(string s)
{
   int ans=0;
   for(int i=0; i<s.size(); i++)
   {
         int c=0;
         for(int j=i; j<s.size(); j++)
         {
            if(s[i]==s[j])c++;
            else break;
         }
         i+=(c-1);
         ans+=(c*(c+1))/2;
   }
   cout<<ans<<endl;
}
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
    string s;
    cin>>s;
    palin(s);
    }

}

