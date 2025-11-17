#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

const int maxN = 3e6 + 100;

int power(int a, int n) {
    int ans = 1;
    for (; n; n >>= 1, a = 1LL * a * a % MOD) {
        if (n & 1) {
            ans = 1LL * ans * a % MOD;
        }
    }
    return ans;
}

int inverse(int a) {
    return power(a, MOD - 2);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m + 1; j++) cin >> a[i][j];
    }
    // Gauss-Jordan elimination
    int row = 0;
    vector<int> where(m, -1);  // where[col] = row index that has pivot for col
    for (int col = 0; col < m && row < n; col++) {
        int pivot = -1;
        for (int i = row; i < n; i++) {
            if (a[i][col] != 0) {
                pivot = i;
                break;
            }
        }
        if (pivot == -1) {
            continue;
        }
        swap(a[pivot], a[row]);
        // normalize pivot to 1
        int inv = inverse(a[row][col]);
        for (int j = col; j <= m; j++) {
            a[row][j] = 1LL * a[row][j] * inv % MOD;
        }
        // eliminate all other rows
        for (int i = 0; i < n; i++) {
            if (i == row) continue;
            if (a[i][col] == 0) continue;
            int factor = a[i][col];
            for (int j = col; j <= m; j++) {
                a[i][j] = (a[i][j] - 1LL * factor * a[row][j] % MOD + MOD) % MOD;
            }
        }
        where[col] = row;
        row++;
    }

    // check for inconsistency: 0 ... 0 | b (with b != 0)
    for (int i = 0; i < n; i++) {
        bool allzero = true;
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                allzero = false;
                break;
            }
        }
        if (allzero && a[i][m]) {
            cout << -1 << '\n';
            return;
        }
    }
    vector<int> x(m, 0);
    for (int j = 0; j < m; j++) {
        if (where[j] != -1) {
            x[j] = a[where[j]][m];
        } else {
            x[j] = 0;
        }
    }
    for (int i = 0; i < m; i++) cout << x[i] << ' ';
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