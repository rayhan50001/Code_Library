#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt,kk=1;
    cin>>tt;
    while(tt--)
    {
        int n,w;
        cin>>n>>w;
        vector<int>v;
        for(int i=0; i<n; i++)
        {
         int x,y;
         cin>>x>>y;
         v.push_back(y);
        }
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0; i<n; i++)
        {
			int y = v[i];
            ans++;
            int c=0;
			for(int j=i+1; j<n; j++)
            {
                if(v[j]-y<=w){i++;continue;}
                else break;
            }

		}
		printf("Case %d: %d\n",kk++,ans);
    }
}
