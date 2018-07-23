#include<bits/stdc++.h>
using namespace std;
int arr[100001];
template<typename T>inline string to_string(T a)
{
    ostringstream os("");
    os << a;
    return os.str();
}
int main()
{
    int n,k;
    while(cin>>k>>n && n && k)
    {
        for(int i=0; i<n; i++)cin>>arr[i];
        int c=1;
        vector<int>v[10000];
        map<string,int>mp;
        for(int i=0; i<(1<<n); i++)
        {
            int sum=0;
            string s;
            for(int j=0; j<n; j++)
            {
                if(i&(1<<j))
                   {
                       s+=to_string(arr[j]);
                       sum+=arr[j];
                   }
            }
            if(sum==k && !mp[s])
            {
                for(int j=0; j<n; j++)
                {
                    if(i&(1<<j))
                    {
                        v[c].push_back(arr[j]);
                    }
                }
                c++;
                mp[s]++;
            }
        }
        sort(v,v+c);
        printf("Sums of %d:\n",k);
        if(c==1)printf("NONE\n");
        else
        {
            for(int i=c-1; i>=1; i--)
            {
                for(int j=0; j<v[i].size(); j++)
                {
                    cout<<v[i][j];
                    if(j<v[i].size()-1)cout<<"+";
                }
                cout<<endl;
            }
        }
    }
}
