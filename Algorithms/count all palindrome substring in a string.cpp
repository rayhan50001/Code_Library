// C++ program to find palindromic substrings of a string
#include<bits/stdc++.h>
using namespace std;

// Returna total number of palindrome substring of
// length greater then equal to 2
bool P[31][31];
int dp[31][31];
int CountPS(char str[], int n)
{

    memset(dp, 0, sizeof(dp));
    memset(P, false , sizeof(P));
    for (int i= 0; i< n; i++)
        P[i][i] = true;
    for (int i=0; i<n-1; i++)
    {
        if (str[i] == str[i+1])
        {
            P[i][i+1] = true;
            dp[i][i+1] = 1 ;
        }
    }
    for (int gap=2 ; gap<n; gap++)
    {
        for (int i=0; i<n-gap; i++)
        {
            int j = gap + i;
            if (str[i] == str[j] && P[i+1][j-1] )
                P[i][j] = true;
            if (P[i][j] == true)
                dp[i][j] = dp[i][j-1] + dp[i+1][j] + 1 - dp[i+1][j-1];
            else
                dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
        }
    }
    return dp[0][n-1];
}
int main()
{
    char str[] = "aaaa";
    int n = strlen(str);
    cout << CountPS(str, n) << endl;
    return 0;
}
