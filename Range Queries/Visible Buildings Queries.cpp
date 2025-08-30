#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
 
void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    // r[i] = smallest j > i that h[j] > h[i]
    // query a b: how many times we can perform l = r[l] <= b, start l = a
    // do binary lifting, jump[i][0] = r[i], jump[i][j] = jump[jump[i][j - 1]][j - 1]
    vector<int> r(n, n);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        while (stk.size() && h[i] > h[stk.top()]) {
            r[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    int lg = 0;
    while ((1 << lg) <= n) lg++;
    vector<vector<int>> jump(n, vector<int>(lg, 0));
    for (int i = 0; i < n; i++) {
        jump[i][0] = r[i];
    }
    for (int j = 1; j < lg; j++) {
        for (int i = 0; i < n; i++) {
            int p = jump[i][j - 1];
            if (p == n) {
                jump[i][j] = n;
            } else {
                jump[i][j] = jump[p][j - 1];
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        int ans = 1;
        for (int k = lg - 1; a <= b && k >= 0; k--) {
            if (jump[a][k] <= b) {
                ans += 1 << k;
                a = jump[a][k];
            }
        }
        cout << ans << '\n';
    }
}
 
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}