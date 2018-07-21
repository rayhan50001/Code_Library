ll fa[MAX] = {0}, fainv[MAX] = {0};                 // fa and fainv must be in global
ll C(ll n, ll r) {                                  // Usable if MOD value is present
    if(fa[0] == 0) {                                // Auto initialize
        fa[0] = 1, fainv[0] = powerMOD(1, MOD-2);
        for(int i = 1; i < MAX; ++i) {
            fa[i] = (fa[i-1]*i) % MOD;              // Constant MOD
            fainv[i] = powerMOD(fa[i], MOD-2);
    }}
    //cerr << "DONE\n";
    if(n < 0 || r < 0 || n-r < 0) return 0;         // Exceptional Cases
    return ((fa[n] * fainv[r])%MOD * fainv[n-r])%MOD;
}
ll NumOfSameValueInCombination(int n, int r)
{          // Returns number of same value in a set of nCr combination
    if(n < r) return 0;
    n = r + abs(n-r);
    return C(n-1, r-1);
}
//link: https://math.stackexchange.com/questions/507681/problem-permutation-and-combination-in-how-many-ways-can-we-divide-12-studen
