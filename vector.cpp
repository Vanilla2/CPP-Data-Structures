#include <iostream>
using namespace std;

template <class T> class vector {
    
    private:
        int p_size;
        int p_capacity;
        T *data;

    public: 
        vector () {
            p_size = 0;
            p_capacity = 1;
            data = new T[1];
        }

        vector(int n) {
            p_size = n;
            p_capacity = n;
            T *newData = new T[n];
        }

        vector(int n, T initial) {
            p_size = n;
            p_capacity = n;
            T *newData = new T[n];
            for (int i = 0; i < n; i++){
                newData[i] = initial;
            }
            data = newData;
        }
        void push_back (T value) {
            p_size++;
            if (p_size > p_capacity) {
                T *newData = new T[2 * p_size];
                p_capacity = 2 * p_size;
                for (int i = 0; i < p_size - 1; i++){
                    newData[i] = data[i];
                }
                T *oldData = data;
                data = newData;
                delete[] oldData;
            }
            data[p_size-1] = value;
        }
        void pop_back () {
            p_size--;
        }
        int size() {
            return p_size;
        }
        T* begin() {
            return data;
        }
        T* end() {
            return &data[p_size];
        }
        T &operator[](int i) {
            return data[i];
        }
};

int main(){
    // Example
    vector <int> v (3,1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    cout << v.end() << " " << &v[v.size()];
    return 0;
}
