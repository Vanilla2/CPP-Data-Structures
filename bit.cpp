#include <iostream>
#include <vector>
using namespace std;

template <class T> class bit {

    private:
        vector <T> arr;
        int n;

    public: 
        bit(int maxval) {
            n = maxval;
            arr.resize(maxval);
        }

        void update (int pos, int val) {
            for (int i = pos; i < n; i+= (i & -i)) {
                arr[i] += val;
            }
        }

        T query (int k) {
            T s = 0;
            for (int i = k; i>= 1; i-= (i & -i)) {
                s+=arr[i];
            }
            return s;
        }
};

int main(){
    // Example
    bit <int> d (500);
    d.update(3, 5);
    d.update(5, 5);
    cout << d.query(4) << " " << d.query(6);
    return 0;
}
