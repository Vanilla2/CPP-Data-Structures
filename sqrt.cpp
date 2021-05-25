#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

template <class T> class sqrt_desc {
    private: 
        vector <T> a;
        vector <T> pr;
        int n, sz;

    public:
        sqrt_desc(vector <T> in) {
            a = in;
            n = a.size();
            sz = sqrt(n) + 1;
            pr.resize(sz, 0);
            for (int i = 0; i < n; i++){
                pr[i / sz] = calc(pr[i / sz], a[i]);
            }
        }

        T query (int l, int r) {
            T rs = 0;
            while (l % sz != 0 && l <= r) {
                rs = calc(rs, a[l]);
                l++;
            }
            while (l + sz <= r) {
                rs = calc(rs, pr[l / sz]);
                l+=sz;
            }
            while (l <= r) {
                rs = calc(rs, a[l]);
                l++;
            }
            return rs;
        }

        T calc (T a, T b) {
            return a + b;
        }
};
 
int main(){
    // Example
    int n;
    cin >> n;
    vector <int> a (n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sqrt_desc <int> sq (a);
    int k;
    cin >> k;
    while (k--){
        int l,r;
        cin >> l >> r;
        cout << sq.query(l,r) << "\n";
    }
    return 0;
}
