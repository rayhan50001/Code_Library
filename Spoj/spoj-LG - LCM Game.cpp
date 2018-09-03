import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
class LCM
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		while(sc.hasNextInt())
		{
			int n=sc.nextInt();
			BigInteger arr [] = new BigInteger[n+1];
			for(int i=0; i<n; i++)arr[i]=sc.nextBigInteger();
			BigInteger lcm=BigInteger.valueOf(1);
			for(int i=0; i<n; i++)
			{
				lcm=LCM(lcm,arr[i]);
			}
			System.out.println(lcm);
		}
	}
	public static BigInteger  LCM(BigInteger a,BigInteger b)
   {
       return a.divide(a.gcd(b)).multiply(b);
    }
}
