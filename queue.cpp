#include <iostream>
using namespace std;

template <class T> class queue {

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
        queue() {
            p_size = 0;
            frontp = NULL;
            backp = NULL;
        }

        void push(T value) {
            node *newNode = new node;
            newNode->value = value;
            newNode->prev = backp;
            newNode->next = NULL;
            if (backp != NULL) backp->next = newNode;
            if (frontp == NULL) frontp = newNode;
            backp = newNode;
            p_size++;
        }

        void pop() {
            node *firstNode = frontp;
            frontp = frontp->next;
            delete firstNode;
        }

        T front() {
            return frontp->value;
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
    queue <int> q;
    q.push(22);
    q.push(23);
    q.push(26);
    q.push(27);
    q.pop();
    q.show_from_back();
    q.show_from_front();
    return 0;
}
