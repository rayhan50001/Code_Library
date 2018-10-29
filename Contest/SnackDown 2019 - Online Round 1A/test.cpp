#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(NULL));
    freopen("in.txt","w",stdout);
    int tt;
    tt=30000;
    cout<<tt<<endl;
    while(tt--)
    {
        int n=rand()%50+1;
        cout<<n<<" ";
        for(int i=0; i<n; i++)
        {
            int x=(rand()%50+1);
            if(x==0)x+=2;
            else if(x==1)x++;
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
