#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    map<int, int> frequency;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        frequency[x]++;
    }
    int ans = 1;
    for (auto &[value, count] : frequency) {
        ans = 1LL * ans * (count + 1) % MOD;
    }
    ans = (ans - 1 + MOD) % MOD;
    cout << ans << '\n';
}
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}