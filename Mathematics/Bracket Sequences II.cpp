#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

const int maxN = 3e6 + 100;

int fact[maxN];
void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; i++) fact[i] = 1LL * fact[i - 1] * i % MOD;
}

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

int nCk(int n, int k) {
    if (n < k) return 0;
    int TS = fact[n];
    int MS = 1LL * fact[k] * fact[n - k] % MOD;
    return 1LL * TS * inverse(MS) % MOD;
}

void solve() {
    init();
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n & 1) {
        cout << 0;
        return;
    }
    n /= 2;
    int open = 0, close = 0;
    for (char c : s) {
        if (c == '(') {
            open++;
        } else {
            close++;
        }
        if (open < close) {
            cout << 0;
            return;
        }
    }
    cout << (nCk(2 * n - open - close, n - open) - nCk(2 * n - open - close, n - 1 - open) + MOD) % MOD << '\n';
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