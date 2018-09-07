//PASSED ALL TEST CASE FROM UDEBUG BUT STILL WA :'( AGAIN SUBMIT
#include<bits/stdc++.h>
using namespace std;
int A[101][101];
int B[101][101];
int vis[101][101];
int main()
{
    //freopen("out.txt","w",stdout);
    int tt,kk=1;
    cin>>tt;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>A[i][j];
                vis[i][j]=0;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>B[i][j];
            }
        }
//        if(kk==76)
//        {
//            for(int i=0; i<n; i++){
//                for(int j=0; j<n; j++)
//                    cout<<A[i][j];
//                cout<<endl;
//            }
//            cout<<endl;
//            for(int i=0; i<n; i++){
//                for(int j=0; j<n; j++)
//                    cout<<B[i][j];
//                cout<<endl;
//            }
//            system("pause");
//        }
        int hobei_ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(A[i][j]!=B[i][j])hobei_ans++;
            }
        }
        cout<<"Case "<<kk++<<": ";
        if(hobei_ans==0)
        {
            cout<<0<<endl;
            continue;
        }
        int symetry=0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(B[i][j]!=B[j][i])
                {
                    symetry++;
                }
            }
        }
        //cout<<symetry<<endl;
        if(symetry==0)
        {
            cout<<"-1\n";
            continue;
        }
        int A_T_B=0;
        int Nai=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                    int ii=i;
                    int jj=j;
                    if(A[ii][jj]!=B[jj][ii] || B[ii][jj]!=A[jj][ii])
                    {
                        Nai=1;
                        break;
                    }
                    if((A[ii][jj]!=B[jj][ii] || A[jj][ii]!=B[ii][jj]) && B[ii][jj]!=B[jj][ii])
                    {
                        A_T_B++;
                    }
            }
            if(Nai)break;
        }
        if(Nai || A_T_B>1)
        {
            cout<<hobei_ans<<endl;
            continue;
        }
        if(n==2 && m==2)cout<<"-1\n";
        else if(m==2)cout<<hobei_ans+2<<endl;
        else cout<<hobei_ans+1<<endl;
    }
}
