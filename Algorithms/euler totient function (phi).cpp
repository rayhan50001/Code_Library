//count of numbers in {1, 2, 3, …, n} that are relatively prime to n, i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1

int Phi[MAX_N] ;

void EulerPHI(){
    for(int i = 1 ; i < MAX_N ; i++)Phi[i] = i ;
        for(int i = 2 ; i < MAX_N ; i++)
            if(Phi[i] == i)
                for(int j = i ; j < MAX_N ; j += i)
                    Phi[j] = (Phi[j]/i) * (i - 1) ;
}
