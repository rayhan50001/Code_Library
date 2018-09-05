#include<bits/stdc++.h>
using namespace std;
char grid[20][20];
vector<string>eq;
vector<string>rightbig;
vector<string>leftbig;
int ans(int n){
    int c1=0,c0=0;
    while(n)
    {
        if(n%2==0)c0++;
        else c1++;
        n/=2;
    }
    return (c1*500+c0*250);
}
void define()
{
     eq.clear();
    rightbig.clear();
    leftbig.clear();
    eq.push_back("........||........");
    eq.push_back(".../\\...||.../\\...");
    eq.push_back("../..\\..||../..\\..");
    eq.push_back("./....\\.||./....\\.");
    eq.push_back("/......\\||/......\\");
    eq.push_back("\\______/||\\______/");
    eq.push_back("........||........");
    rightbig.push_back(".../\\...||........");
    rightbig.push_back("../..\\..||........");
    rightbig.push_back("./....\\.||.../\\...");
    rightbig.push_back("/......\\||../..\\..");
    rightbig.push_back("\\______/||./....\\.");
    rightbig.push_back("........||/......\\");
    rightbig.push_back("........||\\______/");
    leftbig.push_back("........||.../\\...");
    leftbig.push_back("........||../..\\..");
    leftbig.push_back(".../\\...||./....\\.");
    leftbig.push_back("../..\\..||/......\\");
    leftbig.push_back("./....\\.||\\______/");
    leftbig.push_back("/......\\||........");
    leftbig.push_back("\\______/||........");

}
int main()
{
    //freopen("out.txt","w",stdout);
    int tt,kk=1;
    cin>>tt;
    while(tt--)
    {
        define();
        int n=8;
        int m=18;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>grid[i][j];
            }
        }
        long long c1=0,c2=0;
        int pos_f=-1,pos_s=-1;
        string left,right;
        for(int i=0; i<n; i++)
        {
            int st=-1;
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]=='|')st=j;
                if(st==-1)
                {
                    if(grid[i][j]>='A' && grid[i][j]<='Z'){
                    left+=grid[i][j];
                    c1+=ans((int)grid[i][j]);
                    }
                    if(grid[i][j]=='_')pos_f=i+1;
                }
                else
                {
                    if(grid[i][j]>='A' && grid[i][j]<='Z'){
                    right+=grid[i][j];
                    c2+=ans((int)grid[i][j]);
                    }
                    if(grid[i][j]=='_')pos_s=i+1;
                }
            }
        }
        cout<<"Case "<<kk++<<":\n";

        if(c1==c2)
        {
            if(pos_f==pos_s)
                { printf("The figure is correct.\n");  continue; }
            for(int i=0; i<left.size(); i++)
                {
                    eq[4][i+1]=left[i];
                }
                for(int i=0; i<right.size(); i++)
                {
                    eq[4][i+11]=right[i];
                }
             for(int i=0; i<7; i++)
                {
                    for(int j=0; j<18; j++)
                    {
                        cout<<eq[i][j];
                    }
                    cout<<endl;
                }
        }
        else if(c1>c2)
        {
            if(pos_f>pos_s){ printf("The figure is correct.\n");  continue; }
            for(int i=0; i<left.size(); i++)
                {
                    leftbig[5][i+1]=left[i];
                }
                for(int i=0; i<right.size(); i++)
                {
                    leftbig[3][i+11]=right[i];
                }
            for(int i=0; i<7; i++)
                {
                    for(int j=0; j<18; j++)
                    {
                        cout<<leftbig[i][j];
                    }
                    cout<<endl;
                }
        }
        else if(c2>c1)
        {
            if(pos_s>pos_f){ printf("The figure is correct.\n");  continue; }
            for(int i=0; i<left.size(); i++)
            {
                rightbig[3][i+1]=left[i];
            }
            for(int j=0; j<right.size(); j++)
            {
                rightbig[5][j+11]=right[j];
            }
             for(int i=0; i<7; i++)
                {
                    for(int j=0; j<18; j++)
                    {
                        cout<<rightbig[i][j];
                    }
                    cout<<endl;
                }
        }
    }
}
