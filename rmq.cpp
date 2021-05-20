#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;

template <class T> class rmq {
    private: 
        vector <vector <T> > dp;
        vector <T> a;

    public:
        rmq(vector <T> in) {
            int n = in.size();
            a = in;
            dp.resize(n, vector <T> (log2(n) + 1));
            for (int i = 0; i < n; i++) {
                dp[i][0] = a[i];
            }
            for (int j = 1; j <= log2(n); j++) {
                for (int i = 0; i + (1 << j) <= n; i++) {
                    dp[i][j] = min(dp[i][j-1], dp[i + (1 << (j - 1))][j-1]);
                }
            }
        }

        T get_min(int l, int r) {
            int pw = log2(r - l + 1);
            T rs = min(dp[l][pw], dp[r - (1 << pw) + 1][pw]);
            return rs;
        }
};
 
int main(){
    // Example
    int n,q;
    cin >> n >> q;
    vector <int> a (n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    rmq <int> rq (a);
    while (q--) {
        int l,r;
        cin >> l >> r;
        cout << rq.get_min(l - 1, r -1) << "\n";
    }
    return 0;
}
