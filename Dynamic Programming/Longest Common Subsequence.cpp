#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = ((i > 0 && j > 0) ? dp[i - 1][j - 1] : 0) + 1;
            } else {
                if (i) dp[i][j] = dp[i - 1][j];
                if (j) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }
    }
    int pi = 0, pj = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] > dp[pi][pj]) {
                pi = i;
                pj = j;
            }
        }
    }
    cout << dp[pi][pj] << '\n';
    vector<int> values;
    while (pi >= 0 && pj >= 0) {
        if (a[pi] == b[pj]) {
            values.push_back(a[pi]);
            pi--;
            pj--;
        } else {
            if (pi && dp[pi][pj] == dp[pi - 1][pj]) {
                pi--;
            } else {
                pj--;
            }
        }
    }
    reverse(values.begin(), values.end());
    for (int v : values) cout << v << ' ';
    cout << '\n';
}
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}