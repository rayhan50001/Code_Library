int lcs[1000][1000];
int LCS(string a,string b)
{
    for(int i=0; i<=a.size(); i++)
    {
        for(int j=0; j<=b.size(); j++)
        {
            if(i==0 || j==0)lcs[i][j]=0;
            else if(a[i-1]==b[j-1])
            {
                lcs[i][j]=1+lcs[i-1][j-1];
            }
            else
            {
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
    return lcs[a.size()][b.size()];
}
