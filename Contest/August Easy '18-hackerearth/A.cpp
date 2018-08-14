#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s1,s2;
    cin>>n>>s1>>s2;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        if(s1[i]==s2[i])continue;
        int v1=int(s1[i]);
        int v2=int(s2[i]);
        else if (v1 < v2)
        {
            int left=abs(v1-v2);
			ans+=(left%13+left/13);
		}
		else
		{
			int left=90-v1+v2-64;
			ans+=(left%13+left/13);
		}
    }
    cout<<ans<<endl;
}
