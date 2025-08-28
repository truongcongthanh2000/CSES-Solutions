#include <bits/stdc++.h>

using namespace std;

void solve() {
    int nTest;
    cin >> nTest;
    while (nTest--) {
        int x, y;
        cin >> x >> y;
        int n = max(x, y);
        long long L = 1LL * (n - 1) * (n - 1) + 1;
        long long R = 1LL * n * n;
        if (x == n) {
            if (n & 1) cout << L + y - 1 << '\n';
            else cout << R - y + 1 << '\n';
        }
        else {
            if (n & 1) cout << R - x + 1 << '\n';
            else cout << L + x - 1 << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    #ifdef THEMIS
        freopen("solve.inp", "r", stdin);
        freopen("solve.out", "w", stdout);
    #endif // THEMIS
    int T;
    ///cin >> T;
    T = 1;
    while (T--) solve();
}
