// C Program to find largest prime
// factor of number
#include <math.h>
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
// A function to find largest prime factor
long long maxPrimeFactors(long long n)
{
    // Initialize the maximum prime factor
    // variable with the lowest one
    long long maxPrime = -1;
    set<int>s;
    // Print the number of 2s that divide n
    while (n % 2 == 0) {
        maxPrime = 2;
        s.insert(2);
        n >>= 1; // equivalent to n /= 2
    }

    // n must be odd at this point, thus skip
    // the even numbers and iterate only for
    // odd integers
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            maxPrime = i;
            s.insert(i);
            n = n / i;
        }
    }

    // This condition is to handle the case
    // when n is a prime number greater than 2
    if (n > 2){
        maxPrime = n;
        s.insert(n);
    }
    cout<<s.size()<<endl;
    return maxPrime;
}

// Driver program to test above function
int main()
{
      long long n = 15;
//    printf("%lld\n", maxPrimeFactors(n));

    //n = 25698751364526;
    n = 1000000000000087;
    n = 1000000000000000;
    n = 999999999999999;
    printf("%lld", maxPrimeFactors(n));

    return 0;
}
