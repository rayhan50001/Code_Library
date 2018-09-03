#include<bits/stdc++.h>
using namespace std;
string s;
int cnt1[100001];
int cnt2[100001];
int check(int res,int k)
{
    for(int i=res; i<=s.size()-1; i++)
    {
     int ase1=cnt1[i]-cnt1[i-res];
     int ase2=cnt2[i]-cnt2[i-res];
     //cout<<res<<" "<<ase<<endl;
     if(min(ase1,ase2)<=k)return 1;
    }
    return 0;
}
int main()
{
    int n,k;
    cin>>n>>k;
    int c_a=0,c_b=0;
    cin>>s;
//    for(int i=0; i<n; i++)
//    {
//        if(s[i]=='a')c_a++;
//        else if(s[i]=='b')c_b++;
//    }
//    char ch='\0';
//    if(c_a>c_b)ch='b';
//    else ch='a';
    cnt1[0]=0;
    cnt2[0]=0;
    s="#"+s;
    for(int i=1; i<=n; i++)
    {
        cnt1[i]=cnt1[i-1]+(s[i]=='a');
        cnt2[i]=cnt2[i-1]+(s[i]=='b');
    }
    int low=1;
    int high=n;
    int ans=0;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(check(mid,k))
        {
            low=mid+1;
            ans=max(ans,mid);
        }
        else high=mid-1;
    }
    cout<<ans<<endl;
}
//6 2 baabab
