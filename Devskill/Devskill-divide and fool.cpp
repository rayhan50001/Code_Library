//1
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve()
{
    ll a,b,c,f=0;
    cin>>a>>b>>c;
    cout<<(ll)a/b<<".";
    a=a%b;
    a*=10;
    while(c)
    {
        //cout<<"\t\t\t"<<a<<" "<<b<<endl;
        if(a>=b)
        {
            cout<<a/b;
            a%=b;
            c--;
            f=1;
        }
        else
        {
            //cout<<"YES\n";
            if(f==1) a=a*10;
            while(c)
            {
                if(a>=b) break;
                cout<<0;
                c--;
                a*=10;
                f=1;
            }
        }
       //system("PAUSE");
    }
    cout<<endl;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
        solve();
}

//2
#include<stdio.h>
int main()
    {
        int k,i,a,b,c,pc,x;
        scanf("%d",&k);
        for(i=1;i<=k;i++){
            scanf("%d %d %d",&a,&b,&c);
            printf("%d",a/b);
            pc=0;
            printf(".");
            a%=b;
            while(pc<c){
                a*=10;
                x=a/b;
                a%=b;
                printf("%d",x);
                pc++;
            }
        printf("\n");
        }
        return 0;
    }
