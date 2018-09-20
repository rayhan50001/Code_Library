
import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
public class Ideone
{
	public static BigInteger [][] dp = new BigInteger[501][51] ;
	public static int n,sum;
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		sum = sc.nextInt();
		for(int i=0; i<=500; i++)
        {
            for(int j=0; j<=50; j++)
            {
                dp[i][j]=BigInteger.valueOf(-1);
            }
        }
		if(sum%2==1)
		System.out.println(0);
		else{
		sum/=2;
		BigInteger ans = solve(0,0);
		}
	}
	public static BigInteger solve(int target,int len)
	{
	    if(target>sum)return BigInteger.valueOf(0);
        if(len==n) return BigInteger.valueOf(sum==target);
        if(dp[target][len].compareTo(BigInteger.valueOf(-1))!=0)return dp[target][len];
        BigInteger ret = BigInteger.valueOf(0);
        for(int i=0; i<=9; i++)
        {
            ret+=solve(target+i,len+1);
        }
        return dp[target][len]=ret;
	}
}
