#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

using namespace std;

const int INF = 1e9 + 7;

struct node {
    int left, right;
    int maxi;
    node * child_left;
    node * child_right;
};

node * build(vector<int> & A, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    node * res = new node;
    res->left = left;
    res->right = right;
    if (left == right) {
        res->child_left = NULL;
        res->child_right = NULL;
        res->maxi = A[left];
    } else {
        int mid = (left + right) / 2;
        res->child_left = build(A, left, mid);
        res->child_right = build(A, mid + 1, right);
        res->maxi = max(res->child_left->maxi, res->child_right->maxi);
    }
    return res;
}

int query(node * root, int left, int right) {
    if (right < root->left || left > root->right) {
        return -INF;
    }
    if (right >= root-> right && left <= root->left) {
        return root->maxi;
    }
    int ans1 = query(root->child_left, left, right);
    int ans2 = query(root->child_right, left, right);
    return max(ans1, ans2);
}

void update(node * root, int idx, int val) {
    if (idx < root->left || idx > root->right) {
        return;
    }
    if (root->left == root->right) {
        root->maxi = val;
        return;
    }
    update(root->child_left, idx, val);
    update(root->child_right, idx, val);
    root->maxi = max(root->child_left->maxi, root->child_right->maxi);
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    node * root = build(A, 0, n - 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        char c;
        cin >> c;
        if (c == 'u') {
            int l, r;
            cin >> l >> r;
            l--;
            A[l] = r;
            update(root, l, r);
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            int ans1 = query(root, l, r);
            int ans2 = -INF;
            for (int q = l; q <= r; q++) {
                if (ans2 < A[q]) {
                    ans2 = A[q];
                }
            }
            if (ans1 == ans2) {
                cout << "OK " << ans1 << endl;
            } else {
                cout << "WA" << endl;
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

using namespace std;

const int INF = 1e9 + 7;

struct node {
    int left, right;
    int maxi;
    node * child_left;
    node * child_right;
};

node * build(vector<int> & A, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    node * res = new node;
    res->left = left;
    res->right = right;
    if (left == right) {
        res->child_left = NULL;
        res->child_right = NULL;
        res->maxi = A[left];
    } else {
        int mid = (left + right) / 2;
        res->child_left = build(A, left, mid);
        res->child_right = build(A, mid + 1, right);
        res->maxi = max(res->child_left->maxi, res->child_right->maxi);
    }
    return res;
}

int query(node * root, int left, int right) {
    if (right < root->left || left > root->right) {
        return -INF;
    }
    if (right >= root-> right && left <= root->left) {
        return root->maxi;
    }
    int ans1 = query(root->child_left, left, right);
    int ans2 = query(root->child_right, left, right);
    return max(ans1, ans2);
}

void update(node * root, int idx, int val) {
    if (idx < root->left || idx > root->right) {
        return;
    }
    if (root->left == root->right) {
        root->maxi = val;
        return;
    }
    update(root->child_left, idx, val);
    update(root->child_right, idx, val);
    root->maxi = max(root->child_left->maxi, root->child_right->maxi);
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    node * root = build(A, 0, n - 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        char c;
        cin >> c;
        if (c == 'u') {
            int l, r;
            cin >> l >> r;
            l--;
            A[l] = r;
            update(root, l, r);
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;
            int ans1 = query(root, l, r);
            int ans2 = -INF;
            for (int q = l; q <= r; q++) {
                if (ans2 < A[q]) {
                    ans2 = A[q];
                }
            }
            if (ans1 == ans2) {
                cout << "OK " << ans1 << endl;
            } else {
                cout << "WA" << endl;
            }
        }
    }
    return 0;
}
