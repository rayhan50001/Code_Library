/*
X%num[1]=rem[1]
.
.
X%num[n]=rem[n]

find minimum X. and both rem and num must be co-prime with each other. answer of X always exist.

x =  ( &Sum; (rem[i]*pp[i]*inv[i]) ) % prod
   Where 0 <= i <= n-1

rem[i] is given array of remainders

prod is product of all given numbers
prod = num[0] * num[1] * ... * num[k-1]

pp[i] is product of all divided by num[i]
pp[i] = prod / num[i]

inv[i] = Modular Multiplicative Inverse of
         pp[i] with respect to num[i]

Example:
Let us take below example to understand the solution
   num[] = {3, 4, 5}, rem[] = {2, 3, 1}
   prod  = 60
   pp[]  = {20, 15, 12}
   inv[] = {2,  3,  3}  // (20*2)%3 = 1, (15*3)%4 = 1
                        // (12*3)%5 = 1

   x = (rem[0]*pp[0]*inv[0] + rem[1]*pp[1]*inv[1] +
        rem[2]*pp[2]*inv[2]) % prod
     = (2*20*2 + 3*15*3 + 1*12*3) % 60
     = (40 + 135 + 36) % 60
     = 11
*/
//code
#include<bits/stdc++.h>
using namespace std;

// Returns modulo inverse of a with respect to m using extended
// Euclid Algorithm. Refer below post for details:
// https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
int inv(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
       return 0;

    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        // q is quotient
        q = a / m;

        t = m;

        // m is remainder now, process same as
        // euclid's algo
        m = a % m, a = t;

        t = x0;

        x0 = x1 - q * x0;

        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
       x1 += m0;

    return x1;
}
int findMinX(int num[], int rem[], int k)
{
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];
    int result = 0;
    for (int i = 0; i < k; i++)
    {
        int pp = prod / num[i];
        result += rem[i] * inv(pp, num[i]) * pp;
    }

    return result % prod;
}
int main(void)
{
    int num[] = {3, 4, 5};
    int rem[] = {2, 3, 1};
    int k = sizeof(num)/sizeof(num[0]);
    cout << "x is " << findMinX(num, rem, k);
    return 0;
}
