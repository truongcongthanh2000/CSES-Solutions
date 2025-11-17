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

// https://www.geeksforgeeks.org/dsa/orbit-counting-theorem-or-burnsides-lemma/
void solve() {
    int n, m;
    cin >> n >> m;
    int ans = 0, divide = inverse(n);
    for (int i = 0; i < n; i++) {
        int g = __gcd(i, n);
        int way = 1LL * power(m, g) * divide % MOD;
        ans = (ans + way) % MOD;
    }
    cout << ans << '\n';
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