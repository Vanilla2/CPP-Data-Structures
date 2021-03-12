#include <iostream>
using namespace std;

template <class T> class stack {

    struct node {
        T value;
        node* next;
    };

    private:
        node* head;
        int p_size;

    public: 
        stack() {
            p_size = 0;
            head = NULL;
        }

        void push(T value) {
            node *newNode = new node;
            newNode->value = value;
            newNode->next = head;
            head = newNode;
            p_size++;
        }

        void pop() {
            if (head != NULL){
                node *target = head;
                head = target->next;
                delete target;
                p_size--;
            }
        }

        T top() {
            return head->value;
        }

        int size() {
            return p_size;
        }

        void show() {
            node *fake_head = head;
            while (fake_head != NULL){
                cout << fake_head->value << " ";
                fake_head = fake_head->next;
            }
            cout << "\n";
        }
};

int main() {
    // Example
    stack <int> a;
    a.push(3);
    cout << a.top() << "\n";
    a.push(2);
    a.push(90);
    cout << a.top() << "\n";
    cout << a.size();
    return 0;
}
