#include <stdio.h>
#include <string.h>
#include <stack>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define MAXN 131072
#define MAXC 32
int h[MAXN], c[MAXN], sumc[MAXN][MAXC];
int L[MAXN], R[MAXN];
int main() {
    int N, C;
    while (scanf("%d %d", &N, &C) == 2 && N) {
        for (int i = 1; i <= N; i++)
            scanf("%d", &h[i]);
        for (int i = 1; i <= N; i++)
            scanf("%d", &c[i]);
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < C; j++)
                sumc[i][j] = sumc[i-1][j];
            sumc[i][c[i]]++;
        }
        for (int i = 0; i < C; i++)
            sumc[N+1][i] = sumc[N][i];

        h[0] = h[N+1] = 0;
        vector<int> stk;
        stk.push_back(0);
        for (int i = 1; i <= N; i++) {
            while (h[i] <= h[stk.back()])
                stk.pop_back();
            L[i] = stk.back() + 1, stk.push_back(i);
        }

        while (!stk.empty())	stk.pop_back();

        stk.push_back(N + 1);
        for (int i = N; i >= 1; i--) {
            while (h[i] <= h[stk.back()])
                stk.pop_back();
            R[i] = stk.back() - 1, stk.push_back(i);
        }

        long long ret = 0;
        for (int i = 1; i <= N; i++) {
            int ok = 1;
            for (int j = 0; j < C; j++)
                ok &= sumc[R[i]][j] - sumc[L[i] - 1][j] > 0;
            if (ok)
                ret = max(ret, (long long) h[i] * (R[i] - L[i] + 1));
        }
        printf("%lld\n", ret);
    }
    return 0;
}
