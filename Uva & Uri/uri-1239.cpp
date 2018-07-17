#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("out.txt","w",stdout);
    char s[10001];
    while(gets(s))
    {
        int len=strlen(s);
        bool isStar=false,isUnder=false;
        for(int i=0; i<len; i++)
        {
            if(s[i]=='_' && isUnder==false)
            {
                cout<<"<i>";
                isUnder=true;
                continue;
            }
            if(s[i]=='_' && isUnder==true)
            {
                cout<<"</i>";
                isUnder=false;
                continue;
            }
            if(s[i]=='*' && isStar==false)
            {
                cout<<"<b>";
                isStar=true;
                continue;
            }
            if(s[i]=='*' && isStar==true)
            {
                cout<<"</b>";
                isStar=false;
                continue;
            }
            cout<<s[i];
        }
        cout<<endl;
    }
}
