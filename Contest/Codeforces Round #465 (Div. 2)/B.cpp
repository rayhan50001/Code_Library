#include<bits/stdc++.h>
using namespace std;
int arr[100009];
int brr[100009];
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int x=0;
    int y=0;
    int c=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='U')y++;
        else if(s[i]=='R')x++;
        arr[i]=x;
        brr[i]=y;
    }
    for(int i=0; i<n; i++)
    {
        if(arr[i]==brr[i])c++;
    }
    cout<<c<<endl;
}
