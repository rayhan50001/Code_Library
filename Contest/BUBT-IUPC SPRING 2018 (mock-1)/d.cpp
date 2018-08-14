#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tt;
	cin>>tt;
	while(tt--)
	{
	    string s;
	    cin>>s;
	    int c=0;
	    for(int i=0; i<s.size(); i++)
	    if(s[i]>='A' && s[i]<='Z')c++;
	    cout<<c<<endl;
	}
}
