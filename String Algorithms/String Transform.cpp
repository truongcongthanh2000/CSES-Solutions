#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    vector<int> h(s.size());
    iota(h.begin(), h.end(), 0);
    std::stable_sort(h.begin(), h.end(), [&](int i, int j) {
        return s[i] < s[j];
    });
    string ans;
    for (int i = h[0]; i; ) {
        i = h[i];
        ans += s[i];
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