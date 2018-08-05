#include<bits/stdc++.h>
using namespace std;
int grid[1001][1001];
bool if_possible(int i,int j,int n)
{
    for(int ii=0; ii<n; ii++)if(grid[ii][j])return false;//column check
    for(int ii=0; ii<n; ii++)if(grid[i][ii])return false;//row check
    for(int ii=0; ii<n; ii++)
    {
        for(int jj=0; jj<n; jj++)
        {
            if(i+j)
        }
    }
}
void N_Queen(int i,int j,int n,int queen)
{
    if(queen<=0)return true;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(if_possible(i,j,n))
            {

            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    N_Queen(0,0,n,n);
}
