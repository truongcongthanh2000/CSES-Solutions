#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'A']++;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > (n + 1) / 2) {
            cout << -1 << '\n';
            return;
        }
    }
    string ans;
    while (ans.size() < n) {
        // check character with max frequency first to can skip this character ?
        int idx_max_freq = max_element(freq.begin(), freq.end()) - freq.begin();
        int remain = n - ans.size() - 1;
        if (freq[idx_max_freq] > (remain + 1) / 2) { // cannot skip
            ans += char(idx_max_freq + 'A');
            freq[idx_max_freq]--;
            continue;
        }
        for (int c = 0; c < 26; c++) {
            if (freq[c] > 0 && (ans.empty() || ans.back() != char(c + 'A'))) {
                ans += char(c + 'A');
                freq[c]--;
                break;
            }
        }
    }
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