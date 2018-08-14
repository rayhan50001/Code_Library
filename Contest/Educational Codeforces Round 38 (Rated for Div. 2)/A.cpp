#include<bits/stdc++.h>
using namespace std;
bool vowel(char ch)
{
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='y')return true;
    else return false;
}
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    while(true)
    {
        int f=0;
        for(int i=0; i<s.size()-1; i++)
        {
            if(vowel(s[i]) && vowel(s[i+1]))
            {
            f=1;
            s.erase(i+1,1);
            break;
            }
        }
        if(!f)break;
    }
    cout<<s<<endl;
    return 0;
}

