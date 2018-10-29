
//Bismillahir-Rahmanir-Rahim (In The Name Of ALLAH)
#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define base 37
#define ll long long
#define MAX 300001
ll power[1000001];
ll pref[1000001];
void ext_gcd ( long long A, long long B, long long *X, long long *Y ){
    long long x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
//    return r2;
}
long long modInv ( long long a, long long m ) {

    ///ll x = bigmod( a, m - 2, m );    m is a prime       ///(ax)%m = 1

    long long x, y;
    ext_gcd( a, m, &x, &y );

    ///Process x so that it is between 0 and m-1
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}

/* Suffix Array ------------------------------------------------------------------------*/

int o[2][MAX], t[2][MAX];
int idxToRank[MAX], rankToIdx[MAX], A[MAX], B[MAX], C[MAX], D[MAX];

void SuffixArray(string str, int len, int maxAscii = 256) {     // use ~ as a distinguishing charechter
    int x = 0;
    memset(A, 0, sizeof A);
    memset(C, 0, sizeof C);
    memset(D, 0, sizeof D);
    memset(o, 0, sizeof o);
    memset(t, 0, sizeof t);

    for(int i = 0; i < len; ++i) A[(str[i]-'A')] = 1;
    for(int i = 1; i < maxAscii; ++i) A[i] += A[i-1];
    for(int i = 0; i < len; ++i) o[0][i] = A[(int)(str[i]-'A')];

    for (int j = 0, jj = 1, k = 0; jj < len && k < len; ++j, jj <<= 1) {
        memset(A, 0, sizeof A);
        memset(B, 0, sizeof B);
        for(int i = 0; i < len; ++i) {
            ++A[ t[0][i] = o[x][i] ];
            ++B[ t[1][i] = (i+jj<len) ? o[x][i+jj] : 0 ];
        }
        for(int i = 1; i <= len; ++i) {
            A[i] += A[i-1];
            B[i] += B[i-1];
        }
        for(int i = len-1; i >= 0; --i)
            C[--B[t[1][i]]] = i;
        for(int i = len-1; i >= 0; --i)
            D[--A[t[0][C[i]]]] = C[i];
        x^=1;
        o[x][D[0]] = k = 1;
        for(int i = 1; i < len; ++i)
            o[x][D[i]]= (k += (t[0][D[i]] != t[0][D[i-1]] || t[1][D[i]] != t[1][D[i-1]]));
    }
    for(int i = 0; i < len; i++) {
        idxToRank[i] = o[x][i]-1;
        rankToIdx[o[x][i]-1] = i;
}}

// Longest Common Prefix: Kasai's Algorithm
// Complexity: O(n)

int lcp[MAX];
void Kasai(int len, string str) {               // Matches Same charechters with i'th rank & (i+1)'th rank
    int match = 0;
    for(int idx = 0; idx < len; ++idx) {
        if(idxToRank[idx] == len-1) {
            match = 0;
            continue;
        }
        int nxtRankIdx = rankToIdx[idxToRank[idx]+1];
        while(idx+match < len and nxtRankIdx+match < len and str[idx+match] == str[nxtRankIdx+match])
            ++match;
        lcp[nxtRankIdx] = match;                // the lcp match of i'th & (i+1)'th is stored in
        match -= match>0;                       // the index of (i+1)'th suffix's index
}}

// Longest Common Prefix [Sparse Table after running Kasai]
int table[MAX][23], lg[MAX];
void buildSparseTableRMQ(int n) {                           //  O(n Log n)
    for(ll i = 0; 1LL << i < n; i++)
        lg[1LL << i] = i;
    for(ll i = 1; i < n; i++)
        lg[i] = max(lg[i], lg[i - 1]);
    for(int i = 0; i < n; ++i)
        table[i][0] = i;
    for(int j = 1; (1 << j) <= n; ++j)                      // 2^j
        for(int i = 0; i + (1 << j) - 1< n; ++i) {          // For every node
            if(lcp[rankToIdx[table[i][j-1]]] < lcp[rankToIdx[table[i + (1 << (j-1))][j-1]]])
                table[i][j] = table[i][j-1];
            else
                table[i][j] = table[i + (1 << (j-1))][j-1];
}}

int sparseQueryRMQ(int l, int r) {                          // Gives LCP of index l, r in O(1)
    //l = idxToRank[l], r = idxToRank[r];
    if(l > r) swap(l, r);
    ++l;
    int k = lg[r - l + 1];                                // log(2);
    return min(lcp[rankToIdx[table[l][k]]], lcp[rankToIdx[table[r - (1 << k) + 1][k]]]);
}


// Gives Upper (lower index) for which the Range minimum LCP is tlen
// Call : 0, PosRank, strlen, totstring_len
int rankUP(int lo, int hi, int tlen, int len) {
    int mid, ret = hi, pos = hi;
    --hi;
    while(lo <= hi) {
        mid = (lo+hi)>>1;
        if(sparseQueryRMQ(mid, pos) >= tlen)
            hi = mid-1, ret = mid;
        else
            lo = mid+1;
    }
    return ret;
}

// Gives Lower (higher index) for which the Range minimum LCP is tlen
// Call : PosRank, len-1 strlen, totstring_len
int rankDown(int lo, int hi, int tlen, int len) {
    int mid, ret = lo, pos = lo;
    ++lo;
    while(lo <= hi) {
        mid = (lo+hi)>>1;
        if(sparseQueryRMQ(mid, pos) >= tlen)
            lo = mid+1, ret = mid;
        else
            hi = mid-1;
    }
    return ret;
}
/*-------------------------------------------------------------------------------------------------*/

void poww()
{
    power[0]=1;
    for(int i=1; i<=1000001; i++)power[i]=(power[i-1]%MOD*base%MOD)%MOD;
}
void HASH(string s)
{
    pref[0]=0;
    for(int i=1; i<=s.size(); i++)
    {
        pref[i]=(pref[i-1]%MOD+(power[i-1]*s[i-1])%MOD)%MOD;
    }
}
int main()
{
    poww();
    string s;
    cin>>s;
    HASH(s);

    SuffixArray(s, s.size());
    Kasai(s.size(), s);
    buildSparseTableRMQ(s.size());

//    for(int i = 0; i < s.size(); ++i)
//        cout << i << " : " << rankToIdx[i] << " : " << lcp[rankToIdx[i]] << " " << s.substr(rankToIdx[i]) << endl;

    int n=s.size();
    vector<pair<int,int> >v;
    for(int i=0; i<s.size(); i++)
    {
        int l=i+1;
        //cout<<l<<" "<<n-l+1<<" "<<power[n-l]<<endl;
        ll hash1=pref[l]%MOD;
        ll ha=(pref[n]-pref[n-l]+MOD)%MOD;
        ll md=modInv(power[n-l],MOD);
        ll hash2=(ha%MOD*md%MOD)%MOD;
        if(hash1==hash2)
        {
            int upIdx = rankUP(0, idxToRank[0], l, s.size());
            int dIdx = rankDown(idxToRank[0], (int)s.size()-1, l, (int)s.size());
            v.push_back({l,dIdx-upIdx+1});
            //cerr << "up " << upIdx << " down " << dIdx << endl;
            //cerr << s.substr(0,l)<<" "<<dIdx-upIdx+1<<endl;
        }
    }
    //sort(v.begin(),v.end());
    printf("%d\n",v.size());
    for(int i=0; i<v.size(); i++)
    {
      printf("%d %d\n",v[i].first,v[i].second);
    }
}


