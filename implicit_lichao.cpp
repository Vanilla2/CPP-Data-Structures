#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int maxn = 2e5 + 2;

struct line {
    int64 m;
    int64 b; // m * x + b;

    int64 calc (int64 x) {
        return m * x + b;
    }
};

struct lichao {
    int64 l,r;
    line v;

    lichao* left = NULL;
    lichao* right = NULL;

    lichao(int _l, int _r, line _v): l(_l), r(_r), v(_v) {};

    inline void extend () {
        if (left != NULL) return;
        int64 mid = (l + r) / 2;
        left = new lichao(l, mid, {0, (int64) -1e18});
        right = new lichao(mid + 1, r, {0, (int64) -1e18});
    }

    inline void update (line ln) {
        if (l == r) {
            if (ln.calc(l) > v.calc(l)) v = ln;
            return;
        }
        extend();
        int64 mid = (l + r) / 2;
        if (ln.m < v.m) swap(ln, v);
        if (ln.calc(mid) > v.calc(mid)) {
            swap(ln, v);
            left->update(ln);
        }
        else right->update(ln);
    }

    inline int64 query (int64 x) {
        if (l == r) return v.calc(x);
        if (l > x || r < x) return -1e18;
        extend();
        return max({left->query(x), right->query(x), v.calc(x)});
    }
};

int main () {
    lichao* lc = new lichao (1, 1e9, {0, (int64) -1e18});
}