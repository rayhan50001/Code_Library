#include<bits/stdc++.h>
using namespace std;
int main()
{
    int low=1;
    int high=1e9;
    while(low<=high)
    {
        int mid=(low+high)/2;
        cout<<"Q "<<mid<<endl;
        cout.flush();
        string s;
        cin>>s;
        if(s==">")
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    cout<<"Q "<<low<<endl;
    cout.flush();
}
