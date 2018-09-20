#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define base 37
#define ll long long
ll power[100001];
ll FHASH[100001];
ll RHASH[100001];

const int MAXN = 3009;

struct node {
    int next[26];
    int len;
    int sufflink;
    int num;
};

int len;
char s[MAXN];
node tree[MAXN];
int num;            // node 1 - root with len -1, node 2 - root with len 0
int suff;           // max suffix palindrome
long long ans;

bool addLetter(int pos) {
    int cur = suff, curlen = 0;
    int let = s[pos] - 'a';

    while (true) {
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
            break;
        cur = tree[cur].sufflink;
    }
    if (tree[cur].next[let]) {
        suff = tree[cur].next[let];
        return false;
    }

    num++;
    suff = num;
    tree[num].len = tree[cur].len + 2;
    tree[cur].next[let] = num;

    if (tree[num].len == 1) {
        tree[num].sufflink = 2;
        tree[num].num = 1;
        return true;
    }

    while (true) {
        cur = tree[cur].sufflink;
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
            tree[num].sufflink = tree[cur].next[let];
            break;
        }
    }

    tree[num].num = 1 + tree[tree[num].sufflink].num;

    return true;
}

void initTree() {
    num = 2; suff = 2;
    tree[1].len = -1; tree[1].sufflink = 1;
    tree[2].len = 0; tree[2].sufflink = 1;
}

void pre()
{
    power[0]=1;
    for(int i=1; i<=10001; i++)
    {
        power[i]=(power[i-1]%MOD*base%MOD)%MOD;
    }
}
void HASH(string s)
{
    FHASH[0]=0;
    RHASH[0]=0;
    for(int i=1; i<=s.size(); i++)
    {
        FHASH[i]=(FHASH[i-1]%MOD+(s[i-1]*power[i-1])%MOD)%MOD;
        RHASH[i]=(RHASH[i-1]%MOD+(s[s.size()-i]*power[i-1])%MOD)%MOD;
    }
}
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
}
long long modInv ( long long a, long long m ) {
    long long x, y;
    ext_gcd( a, m, &x, &y );
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}
int maxlengthc(int ans,int n)
{
    int c=0;
    int l=1;
    for(int r=ans; r<=n; r++,l++)
    {
        int le=l;
        int ri=r;
        ll first=(FHASH[ri]-FHASH[le-1]+MOD)%MOD;
        ll fdow=modInv(power[le-1],MOD);
        ll FIRST=(first%MOD*fdow%MOD)%MOD;
        if(FIRST<0)FIRST+=MOD;
        ll second=(RHASH[n-le+1]-RHASH[n-ri]+MOD)%MOD;
        ll sdow=modInv(power[n-ri],MOD);
        ll SECOND=(second%MOD*sdow%MOD)%MOD;
        if(SECOND<0)SECOND+=MOD;
        if(FIRST==SECOND)c++;
    }
    return c;
}
int main()
{
    pre();
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("%s",s);
        len=strlen(s);
        HASH(s);
        initTree();
        int length=0;
        for (int i = 0; i < len; i++)
        {
        addLetter(i);
        //cout<<"yes\n";
        length=max(length,tree[suff].len);
        }
        for (int i = 0; i < len; i++)
        {
        tree[i].sufflink=0;
        tree[i].len=0;
        tree[i].num=0;
        memset(tree[i].next,'\0',sizeof(tree[i].next));
        }
        int cntt=maxlengthc(length,len);
        printf("%d %d\n",length,cntt);
    }
}
