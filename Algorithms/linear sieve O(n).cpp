// LINEAR SIEVE -> O(N) COMPLEXITY

bool is_composite[MAX_N] ;
std::vector< int > pm;

void linear_sieve(){
    for(int i = 2 ; i < MAX_N ; i++){
        if(!is_composite[i])pm.push_back(i) ;
        for(int j = 0 ; j < (int)pm.size() and i * pm[j] < MAX_N ; j++){
            is_composite[i * pm[j]] = 1 ;
            if(i % pm[j] == 0)break ;
        }
    }
}
