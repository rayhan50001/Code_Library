#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("input.txt","w",stdout);
    cout<<100<<endl;
    for(int i=0; i<100; i++)
    {
        int n=rand()%1000000009+1;
        cout<<n<<" ";;
        for(int j=0; j<30; j++)
        {
            int b=rand()%2+1;
            if(b%2==1)cout<<"S";
            else cout<<"C";
        }
        cout<<endl;
    }
}
