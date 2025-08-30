#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
/*
Given an array x of n integers, your task is to process q queries of the form:
how many integers i satisfy a <= i <= b and c <= x_i <= d?
*/
const int maxN = 2e5 + 100;
vector<int> IT[maxN * 4];
void build(int i, int l, int r, const vector<int> &x) {
    if (l == r) {
        IT[i].push_back(x[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(i << 1, l, mid, x);
    build(i << 1 | 1, mid + 1, r, x);
    IT[i].resize(r - l + 1);
    merge(IT[i << 1].begin(), IT[i << 1].end(), IT[i << 1 | 1].begin(), IT[i << 1 | 1].end(), IT[i].begin());
}
 
int get(int i, int l, int r, int u, int v, int val) {  // number of i in range [u, v] that x_i <= val
    if (l > v || r < u) {
        return 0;
    }
    if (l >= u && r <= v) {
        return upper_bound(IT[i].begin(), IT[i].end(), val) - IT[i].begin();
    }
    int mid = (l + r) >> 1;
    int left = get(i << 1, l, mid, u, v, val);
    int right = get(i << 1 | 1, mid + 1, r, u, v, val);
    return left + right;
}
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    // a, b, c, d: f(a, b, m) = count x_i <= m -> query = f(a, b, d) - f(a, b, c - 1)
    build(1, 0, n - 1, x);
    while (q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        cout << get(1, 0, n - 1, a, b, d) - get(1, 0, n - 1, a, b, c - 1) << '\n';
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