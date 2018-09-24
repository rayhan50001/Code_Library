#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int h=0;
    for(int i=0; i<s.size()-1; i++)
    {
        if(s[i]=='s' && s[i+1]=='s')
        {
            h=1;
            break;
        }
    }
    if(h)cout<<"hiss\n";
    else cout<<"no hiss\n";
}
