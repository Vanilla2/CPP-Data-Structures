#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int maxn = 2e5 + 2;

struct node {
    int l,r;
    int64 v;

    node* left = NULL;
    node* right = NULL;

    node(int _l, int _r, int64 _v): l(_l), r(_r), v(_v) {};
    
    inline void extend() {
        if (left != NULL) return;
        int mid = (l + r) / 2;
        left = new node(l, mid, 1e15);
        right = new node(mid + 1, r, 1e15);
    }

    inline int64 query (int il, int ir) {
        if (il <= l && r <= ir) return v;
        if (l > ir || r < il) return 1e15;
        extend();
        return min(left->query(il, ir), right->query(il, ir));
    }

    inline void update (int x, int64 nval) {
        if (l == r && l == x) return void(v = nval);
        if (l > x || r < x) return;
        extend();
        left->update(x, nval);
        right->update(x, nval);
        v = min(left->v, right->v);
    }
};
 

int main() {
    node* sg = new node(1, 1e9, 5);
    cout << sg->query(1, 5);
    return 0;
}