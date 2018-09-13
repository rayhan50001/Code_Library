#include<bits/stdc++.h>
using namespace std;
int pref[100001];
void kmp(string s)
{
    int i=1,j=0;
    pref[0]=0;
    int n=s.size();
    while(i<n)
    {
        if(s[i]==s[j])
        {
            j++;
            pref[i]=j;
            i++;
        }
        else
        {
            if(j!=0)
            {
                j=pref[j-1];
            }
            else
            {
                pref[i]=0;
                i++;
            }
        }
    }
}
int main()
{
    string s;
    while(cin>>s && s[0]!='*')
    {
        memset(pref,0,sizeof pref);
        kmp(s);
        int start=0;
        pref[s.size()]=1e9;
        for(int i=0; i<s.size(); i++)
        {
            if(pref[i]==0 || pref[i]==pref[i+1])start=i+1;
        }
        sort(s.begin(),s.end());
        if(s[0]==s[s.size()-1])cout<<s.size()<<endl;
        else
        {
            if(s.size()%start==0 && s.size()!=start)cout<<s.size()/start<<endl;
            else cout<<1<<endl;
        }
    }
}
