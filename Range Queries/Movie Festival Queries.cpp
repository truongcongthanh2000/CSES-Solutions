#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    const int N = 1e6 + 1;
    const int lg = 20;
    int n, q;
    cin >> n >> q;
    // jump[i][j] = min index k after 2^j events start at i
    vector<vector<int>> jump(N, vector<int>(lg, N));
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        jump[a][0] = min(jump[a][0], b);
    }
    for (int i = N - 2; i >= 0; i--) jump[i][0] = min(jump[i][0], jump[i + 1][0]);
    for (int j = 1; j < lg; j++) {
        for (int i = N - 1; i >= 0; i--) {
            int p = jump[i][j - 1];
            if (p != N) {
                jump[i][j] = jump[p][j - 1];
            }
            if (i + 1 < N) {
                jump[i][j] = min(jump[i][j], jump[i + 1][j]);
            }
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        int ans = 0;
        for (int i = lg - 1; i >= 0; i--) {
            if (a <= b && jump[a][i] <= b) {
                ans += 1 << i;
                a = jump[a][i];
            }
        }
        cout << ans << '\n';
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