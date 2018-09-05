//substring match (bruteforce)
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int main()
{
    string s1,s2;
    bool suru=true;
    while(cin>>s1>>s2)
    {
        memset(dp,0,sizeof dp);
        if(!suru)cout<<endl;
        else suru=false;
        int mx=0;
        set<string>s;
        for(int i=0; i<s1.size(); i++)
        {
            for(int j=0; j<s2.size(); j++)
            {
                if(s1[i]==s2[j])
                {
                    int &curr = dp[i][j];
                    curr = i == 0 || j == 0 ? 1 : dp[i - 1][j - 1] + 1;
                    int len=s1.size();
                    if(curr>mx)
                    {
                        mx=curr;
                        s.clear();
                        s.insert(s1.substr(max(0,i-curr+1),min(len,curr)));
                    }
                    else if(mx==curr)
                    {
                        s.insert(s1.substr(max(0,i-curr+1),min(len,curr)));
                    }
                }
                else dp[i][j]=0;
            }
        }

        if(s.size()==0)cout<<"No common sequence.\n";
        else for(auto it: s)cout<<it<<endl;
    }
}
