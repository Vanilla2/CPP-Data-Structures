#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int maxn = 2e5 + 2;

struct node {
    int l,r;
    int64 lazy = 0;
    int64 val = 0;
    node *left = NULL, *right = NULL;

    node(int _l, int _r, int64 _v): l(_l), r(_r), val(_v) {};

    void extend (){
        if (left == NULL) {
            int mid = (l + r) / 2;
            left = new node (l, mid, 0);
            right = new node (mid + 1, r, 0);
        }
    }

    void propagate() {
        extend();
        left->val+=lazy;
        right->val+=lazy;
        left->lazy+=lazy;
        right->lazy+=lazy;
        lazy = 0;
    }
    
    int64 query (int il, int ir) {
        if (l > ir || r < il) return -1e18;
        if (il <= l && r <= ir) return val;
        propagate();
        return max(left->query(il, ir), right->query(il, ir));
    }

    void update (int il, int ir, int64 v) {
        if (l > ir || r < il) return;
        if (il <= l && r <= ir) {
            val += v;
            lazy += v;
            return;
        }
        propagate();
        left->update(il, ir, v);
        right->update(il, ir, v);
        val = max(left->val, right->val);
    }
};

int main() {
    
    return 0;
}