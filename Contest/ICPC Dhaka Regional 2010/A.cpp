#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,kk=1;
    while(cin>>n && n)
    {
        int c1=0,c2=0;
        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            if(x==0)c1++;
            else c2++;
        }
        cout<<"Case "<<kk++<<": "<<c2-c1<<endl;
    }
}
