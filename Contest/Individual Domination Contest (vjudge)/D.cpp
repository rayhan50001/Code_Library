#include<bits/stdc++.h>
using namespace std;
vector<int>vv;
int dp[1001][1001];
int grid[1001][1001];
vector<tuple<int,int,int> >v;
int n,m,k,q;
int sumRegion(int row1, int col1, int row2, int col2) {
    return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
}
void calculate()
{
     for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            dp[r + 1][c + 1] = dp[r + 1][c] + dp[r][c + 1] + grid[r][c] - dp[r][c];
        }
    }
}
bool isvalid(int x,int y)
{
    if(x>=0 && y>=0 && x<n && y<m)return true;
    else return false;
}
bool check(int moment)
{
    for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
    {
        dp[i][j]=0;
        grid[i][j]=0;
    }
    for(int i=0; i<q; i++)
    {
        int curr=get<2>(v[i]);
        int x=get<0>(v[i]);
        int y=get<1>(v[i]);
        //cout<<curr<<" "<<x<<" "<<y<<endl;
        x--;
        y--;
        if(curr<=moment)grid[x][y]=1;
    }
    calculate();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int x1=i;
            int y1=j;
            int x2=x1+k-1;
            int y2=y1+k-1;
            if(isvalid(x2,y2))
            {
            int val=sumRegion(x1,y1,x2,y2);
            //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" ==> "<<val<<"\n";
            if(val==k*k)return 1;
            }
        }
    }
    //system("pause");
    return 0;
}
int main()
{
    cin>>n>>m>>k>>q;
    for(int i=0; i<q; i++)
    {
        int u,uu,t;
        cin>>u>>uu>>t;
        v.push_back(make_tuple(u,uu,t));
        vv.push_back(t);
    }
    sort(vv.begin(),vv.end());
    int ans=INT_MAX;
    int low=1;
    int high=q;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(check(vv[mid-1]))
        {
            ans=min(ans,vv[mid-1]);
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(ans==INT_MAX)ans=-1;
    cout<<ans<<endl;
}
