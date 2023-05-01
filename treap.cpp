#include <bits/stdc++.h>
using namespace std;

struct node {
    int x,y;
    node *l, *r;
    node (int x): x(x), y(rand()), l(NULL), r(NULL) {}
};

void split (node* t, int x, node*& l, node*& r) {
    if (!t) {
        l = r = NULL;
    }
    else if (t->x <= x) {
        split(t->r, x, t->r, r), l = t;
    }
    else {
        split(t->l, x, l, t->l), r = t;
    }
} 

int main(){
    srand(time(NULL));
}