#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int c=0;
    while(n)
    {
        n/=2;
        c++;
    }
    cout<<c-1<<endl;
}
