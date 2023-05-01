#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int maxn = 2e5 + 2;

struct node {
    int l,r;
    int v;

    node* left = NULL;
    node* right = NULL;

    node(int _l, int _r, int _v): l(_l), r(_r), v(_v) {};

    inline int merge (int a, int b) {
        return min(a, b);
    }

    inline void clear() {
        if (left != NULL) {
            left->clear();
            right->clear();
        }
        delete this;
    }
    
    inline void extend() {
        if (left != NULL) return;
        int mid = (l + r) / 2;
        left = new node(l, mid,  1e9);
        right = new node(mid + 1, r, 1e9);
    }

    inline int query (int il, int ir) {
        if (il <= l && r <= ir) return v;
        if (l > ir || r < il) return 1e9;
        extend();
        return merge(left->query(il, ir), right->query(il, ir));
    }

    inline void update (int x, int nval) {
        if (l == r && l == x) return void(v = nval);
        if (l > x || r < x) return;
        extend();
        left->update(x, nval);
        right->update(x, nval);
        v = merge(left->v, right->v);
    }
};

int main() {
    node* sgt = new node (1, 1e9, 1e9);
    cout << sgt->query(1, 1e9);
    sgt->clear();
    return 0;
}