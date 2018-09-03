#include<bits/stdc++.h>
using namespace std;
struct jersey{
 string name;
 int no,id;
}arr[100001];
bool cmp(jersey p1, jersey p2)
{
    if(p1.no==p2.no)
    {
        return p1.id<p2.id;
    }
    else return p1.no<p2.no;
}
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            string s;
            int nn;
            cin>>s>>nn;
            arr[i].name=s;
            arr[i].no=nn;
            arr[i].id=i+1;
        }
        sort(arr,arr+n,cmp);
        cout<<arr[n-1].name<<endl;
    }
}
