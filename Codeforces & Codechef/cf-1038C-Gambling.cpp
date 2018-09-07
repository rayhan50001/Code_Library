#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    vector<int>v1,v2;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v1.push_back(x);
    }
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v2.push_back(x);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    long long A=0,B=0;
    int step=1;
    while(!v1.empty() || !v2.empty())
    {
        int left=0;
        int right=0;
        if(!v1.empty())
        {
            left=v1.back();
        }
        if(!v2.empty())
        {
            right=v2.back();
        }
        if(step%2==1)
        {
            if(left>=right)
            {
                A+=left;
                v1.pop_back();
            }
            else
            {
                v2.pop_back();
            }
        }
        else
        {
            if(left>right)
            {
                v1.pop_back();
            }
            else
            {
                B+=v2.back();
                v2.pop_back();
            }
        }
        step++;
    }
    cout<<A-B<<endl;
}
