#include <bits/stdc++.h>

using namespace std;

struct Node {
    int key, prior, sz;
    Node *l, *r;

    Node() : l(nullptr), r(nullptr), sz(0) {}

    Node(int key_) : key(key_), prior(rand()), l(nullptr), r(nullptr), sz(0) {}
};

typedef Node *PNode;

PNode root = nullptr;

int get_sz(PNode root) {
    if (!root) {
        return 0;
    }
    return root->sz;
}

void update(PNode &root) {
    if (root) {
        root->sz = get_sz(root->l) + get_sz(root->r) + 1;
    }
}

void split(PNode root, PNode &left, PNode &right, int x) {
    if (!root) {
        left = nullptr;
        right = nullptr;
        return;
    }
    if (root->key < x) {
        split(root->r, root->r, right, x);
        left = root;
        update(left);
    } else {
        split(root->l, left, root->l, x);
        right = root;
        update(right);
    }
}

void merge(PNode &root, PNode left, PNode right) {
    if (!left) {
        root = right;
        return;
    }
    if (!right) {
        root = left;
        return;
    }
    if (right->prior > left->prior) {
        merge(right->l, left, right->l);
        root = right;
    } else {
        merge(left->r, left->r, right);
        root = left;
    }
    update(root);
}

void insert(PNode &root, int key) {
    PNode ins = new Node(key);
    PNode x1, x2;
    split(root, x1, x2, key);
    merge(root, x1, ins);
    merge(root, root, x2);
}

void erase(PNode &root, int key) {
    PNode x1, x2, x3;
    split(root, x1, x2, key);
    split(x2, x2, x3, key + 1);
    merge(root, x1, x3);
}

void print(PNode root) {
    if (!root) return;
    print(root->l);
    cout << root->key << ' ';
    print(root->r);
}

bool find(PNode root, int key) {
    if (!root) {
        return false;
    }
    if (root->key == key) {
        return true;
    }
    if (root->key > key) {
        return find(root->l, key);
    } else {
        return find(root->r, key);
    }
}

int get_kth(PNode root, int k) {
    if (!root) {
        return -1;
    }
    if (get_sz(root->l) > k) {
        return get_kth(root->l, k);
    } else if (get_sz(root->l) == k) {
        return root->key;
    } else {
        return get_kth(root->r, k - 1 - get_sz(root->l));
    }
}

int get_num(PNode root, int x) {
    if (!root) {
        return 0;
    }
    if (root->key == x) {
        return get_sz(root->l);
    }
    if (root->key > x) {
        return get_num(root->l, x);
    } else {
        return get_num(root->r, x) + 1 + get_sz(root->l);
    }
}

int main() {
    for (int i = 0; i < 100; ++i) {
        char op;
        int x;
        cin >> op >> x;
        if (op == '+') {
            insert(root, x);
            cout<<"NOW: ";
            print(root);
            cout << endl;
        } else if (op == '-') {
            erase(root, x);
            cout<<"NOW: ";
            print(root);
            cout<<endl;
        } else if (op == 'k'){
            cout << get_kth(root, x) << endl;
        } else {
            cout << get_num(root, x) << endl;
        }
    }
    return 0;
}
