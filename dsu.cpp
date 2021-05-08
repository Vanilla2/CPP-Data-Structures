#include <iostream>
#include <vector>
using namespace std;

template <class T> class dsu {
    private:
        vector <int> parent;

    public:
        dsu() {
            vector <int> el (1000);
            parent = el;
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

        vector <int> getParent(){
            return parent;
        }
};

int main(){
    // Example
    dsu <int> d;
    d.make_set(1);
    d.make_set(2);
    d.make_set(3);
    cout << d.find_set(3) << "\n";
    d.union_sets(1, 2);
    d.union_sets(3, 1);
    cout << d.find_set(1) << "\n";
    cout << d.find_set(2) << "\n";
    vector <int> p = d.getParent();
    for (int i = 0; i < 5; i++) {
        cout << i << " " << p[i] << "\n";
    }
    return 0;
}
