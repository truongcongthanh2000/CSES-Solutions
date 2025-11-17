#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

/*
Create a graph with edge i - p[i]
It will include list of simple cycle
The answer will be lcm of all length simple cycle
*/
map<int, int> prime_factor(int n) {
    map<int, int> m;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int d = 0;
            while (n % i == 0) {
                n /= i;
                d++;
            }
            m[i] = d;
        }
    }
    if (n > 1) {
        m[n] = 1;
    }
    return m;
}
void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> visited(n, 0);
    vector<int> max_power(n, 0);
    int numerator = 1, denominator = 1, gcd = 0, first_cycle = 1;
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }
        int length = 0;
        int u = i;
        while (!visited[u]) {
            visited[u] = 1;
            length++;
            u = p[u];
        }
        if (length == n) {  // edge case simple cycle
            cout << n << '\n';
            return;
        }
        for (auto [p, d] : prime_factor(length)) {
            max_power[p] = max(max_power[p], d);
        }
    }
    int ans = 1;
    for (int p = 2; p < n; p++) {
        for (int d = 0; d < max_power[p]; d++) ans = 1LL * ans * p % MOD;
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