PYTHON:
    import math
    while True:
    try:
        input_ = input()
             except EOFError:
                     break
                     print(str(input_)+"!")
                     print(math.factorial(int(input_)))

JAVA:
    import java.util.*;
    import java.lang.*;
    import java.io.*;
    import java.math.*;
    class Ideone
    {
        public static void main (String[] args) throws java.lang.Exception
        {
            Scanner sc = new Scanner (System.in);
            while(sc.hasNext())
            {
                int n=sc.nextInt();
                BigInteger ans=BigInteger.valueOf(1);
                for(int i=1; i<=n; i++)
                {
                    ans=ans.multiply(BigInteger.valueOf(i));
                }
                System.out.print(n+"!"+"\n"+ans+"\n");
            }
        }
    }
