#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    vector<int> dp(26, 0);
    int cur = 1;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        int ncur = (cur * 2 % MOD - dp[c] + MOD) % MOD;
        dp[c] = cur;
        cur = ncur;
    }
    cout << (cur - 1 + MOD) % MOD << '\n';
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