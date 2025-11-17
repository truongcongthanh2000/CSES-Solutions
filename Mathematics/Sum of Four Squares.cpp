#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int lim = sqrt(n);
    vector<pair<int, int>> a(n + 1, {-1, -1});
    for (int i = 0; i <= lim; i++) {
        for (int j = 0; j <= lim; j++) {
            int v = i * i + j * j;
            if (v > n) break;
            a[v] = {i, j};
        }
    }
    for (int i = 0; i <= n; i++) {
        if (a[i].first != -1 && a[n - i].first != -1) {
            cout << a[i].first << " " << a[i].second << " " << a[n - i].first << " " << a[n - i].second << '\n';
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}