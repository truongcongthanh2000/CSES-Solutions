#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        sum += p[i];
    }
    long long res = 1e9;
    for (int mask = 1; mask < (1 << n); mask++) {
        long long s = 0;
        for (int i = 0; i < n; i++) {
            int bit = (mask >> i) & 1;
            if (bit) {
                s += p[i];
            }
        }
        res = min(res, abs(sum - s - s));
    }
    cout << res;
}

int main(int argc, char *argv[]) {
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
