#include <bits/stdc++.h>
using namespace std;

const int maxn = 200200;

int sgt [maxn * 4];
int a[maxn];
int lazy [maxn * 4];

void push (int x) {
    sgt[2 * x] += lazy[x];
    sgt[2 * x + 1] += lazy[x];
    lazy[2 * x] += lazy[x];
    lazy[2 * x + 1] += lazy[x];
    lazy[x] = 0;
}

int build (int x, int l, int r) {
    if (l == r) return sgt[x] = a[l];
    int mid = (l + r) / 2;
    return sgt[x] = max(build(2 * x, l, mid), build(2 * x + 1, mid + 1, r));
}

int query (int x, int l, int r, int il, int ir) {
    if (il <= l && r <= ir) return sgt[x];
    if (l > ir || r < il) return 0;
    push(x);
    int mid = (l + r) / 2;
    return max(query(2 * x, l, mid, il, ir), query(2 * x + 1, mid + 1, r, il, ir));
}

int update (int x, int l, int r, int il, int ir, int val) {
    if (il <= l && r <= ir){
        lazy[x] += val;
        return sgt[x] += val;
    }
    if (l > ir || r < il) return 0;
    push(x);
    int mid = (l + r) / 2;
    return sgt[x] = max(update(2 * x, l, mid, il, ir, val), update(2 * x + 1, mid + 1, r, il, ir, val));
}


int main(){
    // ios_base::sync_with_stdio(0); cin.tie(0); ct(fixed); ct(setprecision(10)); 
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--) {
        int x,y,z;
        cin >> x >> y >> z;
        if (x == 0) {
            cout << (query(1, 1, n, y, z)) << "\n";
        }
        else {
            int delta;
            cin >> delta;
            update(1, 1, n, y, z, delta);
        }
    }
    return 0;
}