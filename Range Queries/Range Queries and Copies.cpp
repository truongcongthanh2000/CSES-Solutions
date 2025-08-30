#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
struct Node {
    long long sum = 0;
    Node *left = nullptr;
    Node *right = nullptr;
};
 
Node* build(int l, int r, const vector<int> &x){
    Node *root = new Node;
    if (l == r) {
        root->sum = x[l];
        return root;
    }
    int mid = (l + r) >> 1;
    root->left = build(l, mid, x);
    root->right = build(mid + 1, r, x);
    root->sum = root->left->sum + root->right->sum;
    return root;
}
 
Node* update(Node *old, int l, int r, int u, int val) {
    Node *root = new Node;
    if (l == r) {
        root->sum = val;
        return root;
    }
    int mid = (l + r) >> 1;
    if (u <= mid) {
        root->left = update(old->left, l, mid, u, val);
        root->right = old->right;
    } else {
        root->right = update(old->right, mid + 1, r, u, val);
        root->left = old->left;
    }
    root->sum = root->left->sum + root->right->sum;
    return root;
}
 
long long get(Node *root, int l, int r, int u, int v) {
    if (l > v || r < u) return 0;
    if (l >= u && r <= v) return root->sum;
    int mid = (l + r) >> 1;
    long long left = get(root->left, l, mid, u, v);
    long long right = get(root->right, mid + 1, r, u, v);
    return left + right;
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<Node*> roots{build(0, n - 1, x)};
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int k, a, x;
            cin >> k >> a >> x;
            roots[k - 1] = update(roots[k - 1], 0, n - 1, a - 1, x);
        }
        if (t == 2) {
            int k, a, b;
            cin >> k >> a >> b;
            cout << get(roots[k - 1], 0, n - 1, a - 1, b - 1) << '\n';
        }
        if (t == 3) {
            int k;
            cin >> k;
            roots.push_back(roots[k - 1]);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}