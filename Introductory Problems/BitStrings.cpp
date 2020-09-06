#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int res = 1;
    for (int i = 1; i <= n; i++) res = res * 2 % MOD;
    cout << res;
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
