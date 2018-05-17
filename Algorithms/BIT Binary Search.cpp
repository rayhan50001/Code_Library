#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct BIT {
    vector<ll>tree;
    int MaxVal;

    void init(int sz=1e7) {
        tree.resize(sz, 0);
        MaxVal = sz;
    }

    void update(int idx, ll val) {
        while(idx <= MaxVal) {
            //tree[idx] = (tree[idx] + MOD) % MOD;
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }

    void update(int l, int r, ll val) {
        update(l, val);
        update(r+1, val-1);
    }

    ll read(int idx) {
        ll sum = 0;
        while(idx > 0) {
            //sum = (sum + tree[idx] + MOD) % MOD;
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    ll read(int l, int r) {
        ll ret = read(r) - read(l-1);
        //return (ret + MOD)%MOD;
        return ret;
    }

    ll readSingle(int idx) {             // Point read in log(n)
        ll sum = tree[idx];
        if(idx > 0) {
            int z = idx - (idx & -idx);
            --idx;
            while(idx != z) {
                sum -= tree[idx];
                idx -= (idx & -idx);
            }
        }
        return sum;
    }

    int search(int cSum) {		        // Returns the greater index if value is present more than once
        int pos = -1, lo = 1, hi = MaxVal, mid;
        while(lo <= hi) {
            mid = (lo+hi)/2;
            if(read(mid) == cSum) {     // read(mid) >= cSum : can be used to find the lowest index of cSum value
                pos = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return pos;
    }


    /*void scale(int idx = MaxVal) {                      // BIT supports scaling
        for(int i = 0; i < idx; ++i)
            tree[i] %= MOD;
    }*/
};


int main() {
    return 0;
}
