#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    vector<int> dp(n, 0);
    set<int> positions;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && a[i].first == a[j].first) {
            j++;
        }
        for (int k = i; k < j; k++) {
            int p = a[k].second;
            int dp_l = positions.upper_bound(p) == positions.begin() ? 0 : dp[*prev(positions.upper_bound(p))];
            int dp_r = positions.lower_bound(p) == positions.end() ? 0 : dp[*positions.lower_bound(p)];
            dp[p] = max(dp_l, dp_r) + 1;
        }
        for (int k = i; k < j; k++) {
            positions.insert(a[k].second);
        }
        i = j;
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}