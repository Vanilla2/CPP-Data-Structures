#include <iostream>
#include <vector>
using namespace std;
#define db(x) cout << "> " << #x << ": " << x << "\n";

template <class T> class segtree {

    private:
        vector <T> tree;
        int n, il, ir;
        
        void build (vector <T> &a, int node, int l, int r) {
            if (l == r) {
                tree[node] = a[l];
                return;
            }
            int m = (l + r) / 2;
            build(a, node * 2, l, m);
            build(a, node * 2 + 1, m + 1, r);
            tree[node] = calc(tree[node * 2], tree[node * 2 + 1]);
        }
        
        T __query (int node, int l, int r) {
            if (il <= l && r <= ir) return tree[node];
            T s1 = 0, s2 = 0;
            int m = (l + r) / 2;
            if (il <= m) {
                s1 = __query(node * 2, l, m);
            }
            if (m + 1 <= ir) {
                s2 = __query(node * 2 + 1, m + 1, r);
            }
            return calc(s1, s2);
        }

        void __update (int node, int l, int r, int& px, int& val) {
            if (l == r) {
                tree[node] = val;
                return;
            }
            int m = (l + r) / 2;
            if (px <= m) {
                __update(node * 2, l, m, px, val);
            }
            else {
                __update(node * 2 + 1, m + 1, r, px, val);
            }
            tree[node] = calc(tree[node * 2], tree[node * 2 + 1]);
        }

    public: 
        segtree (vector <T> initial) {
            n = initial.size();
            tree.resize(n * 4);
            build(initial, 1, 1, n);
        }

        T query (int l, int r) {
            il = l, ir = r;
            return __query(1, 1, n);
        }

        void update (int pos, int val) {
            return __update(1, 1, n, pos, val);
        }

        T calc (T a, T b) {
            return max(a, b);
        }

};

int main(){
    // Example
    int n, q;
    cin >> n >> q;
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    segtree <int> st (a);
    while (q--) {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 0) {
            cout << (st.query(a,b)) << "\n";
        }
        else {
            st.update(a, b);
        }
    }
    return 0;
}
