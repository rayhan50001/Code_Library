#include<bits/stdc++.h>
using namespace std;
int pref[1000001];
string s;
void kmp()
{
    int n=s.size();
    int i=1,j=0;
    pref[0]=0;
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
int match()
{
    string text=s;
    reverse(s.begin(),s.end());
    kmp();
    string pat=s;
    //cout<<s<<" "<<pat<<endl;
    int n=s.size();
    int m=n;
    int i=0,j=0;
    while(i<n)
    {
        if(text[i]==pat[j])
        {
            j++;
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
                j=0;
                i++;
            }
        }
    }
    return j;
}
int main()
{
    int tt,kk=1;
    scanf("%d",&tt);
    while(tt--)
    {
        cin>>s;
        memset(pref,0,sizeof pref);
        int ans=match();
        int len=s.size();
        //cout<<ans<<endl;
        int res=len+(len-ans);
        printf("Case %d: %d\n",kk++,res);
    }
}
