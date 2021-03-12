#include <iostream>
using namespace std;

template <class T> class deque {

    struct node {
        T value;
        node* next;
        node* prev;
    };

    private:
        node* frontp;
        node* backp;
        int p_size;

    public: 
        deque() {
            p_size = 0;
            frontp = NULL;
            backp = NULL;
        }

        void push_front(T value) {
            node *newNode = new node;
            newNode->value = value;
            newNode->prev = NULL;
            newNode->next = frontp;
            if (backp == NULL) backp = newNode;
            if (frontp != NULL) frontp->prev = newNode;
            frontp = newNode;
            p_size++;
        }

        void push_back(T value) {
            node *newNode = new node;
            newNode->value = value;
            newNode->next = NULL;
            newNode->prev = backp;
            if (frontp == NULL) frontp = newNode;
            if (backp != NULL) backp->next = newNode;
            backp = newNode;
            p_size++;
        }

        T front() {
            return frontp->value;
        }

        T back() {
            return backp->value;
        }

        void pop_front() {
            node *firstNode = frontp;
            frontp = frontp->next;
            delete firstNode;
        }

        void pop_back() {
            node *lastNode = backp;
            backp = backp->prev;
            delete lastNode;
        }

        int size() {
            return p_size;
        }

        void show_from_back() {
            node *fake_back = backp;
            while (fake_back != NULL){
                cout << fake_back->value << " ";
                fake_back = fake_back->prev;
            }
            cout << "\n";
        }

        void show_from_front() {
            node *fake_front = frontp;
            while (fake_front != NULL){
                cout << fake_front->value << " ";
                fake_front = fake_front->next;
            }
            cout << "\n";
        }
};

int main(){
    // Example
    deque <int> d;
    d.push_back(2);
    d.push_front(3);
    d.push_front(4);
    d.show_from_back();
    d.show_from_front();
    return 0;
}
