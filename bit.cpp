#include <iostream>
#include <vector>
using namespace std;

template <class T> class bit {

    private:
        T get_bit(T x) {
            return x & (-x);
        }

        vector <T> arr;

    public: 
        bit(int maxval) {
            arr.resize(maxval);
        }

        void add(int pos, int val) {
            for (int i = pos; i < arr.size(); i+=get_bit(i)) {
                arr[i] += val;
            }
        }

        int get_sum (int k) {
            int s = 0;
            for (int i = k; i>= 1; i-=get_bit(i)) {
                s+=arr[i];
            }
            return s;
        }
};

int main(){
    // Example
    bit <int> d (500);
    d.add(3, 5);
    d.add(5, 5);
    cout << d.get_sum(4) << " " << d.get_sum(6);
    return 0;
}
