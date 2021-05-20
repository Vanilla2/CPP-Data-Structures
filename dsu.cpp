#include <iostream>
#include <vector>
using namespace std;

template <class T> class dsu {
    private:
        vector <T> parent;

    public:
        dsu(int size) {
            parent.resize(size);
        }
        
        void make_set(T val) {
            parent[val] = val;
        }

        void union_sets(T a, T b) {
            a = find_set(a);
            b = find_set(b);
            if (a != b) parent[b] = a;
        }

        T find_set (T node) {
            if (node == parent[node]) return node;
            return parent[node] = find_set(parent[node]);
        }
};

int main(){
    // Example
    dsu <int> d(50);
    d.make_set(1);
    d.make_set(2);
    d.make_set(3);
    cout << d.find_set(3) << "\n";
    d.union_sets(1, 2);
    d.union_sets(3, 1);
    cout << d.find_set(1) << "\n";
    cout << d.find_set(2) << "\n";
    return 0;
}
