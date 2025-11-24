#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

struct Manacher {
    string s;
    int n;
    vector<int> d1, d2;
    Manacher() {};
    Manacher(string _s) {
        s = _s;
        n = (int)s.size();
        d1 = vector<int>(n, 0);
        d2 = vector<int>(n, 0);
        calc();
    }

    void calc() {
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k;
            }
        }
    }

    int getD1(int root) {
        return d1[root];
    }

    int getD2(int root) {
        return d2[root];
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    Manacher man(s);
    vector<int> ans(n, 1);
    for (int i = 0; i < n; i++) {
        int d1 = man.getD1(i);
        ans[i + d1 - 1] = max(ans[i + d1 - 1], d1 * 2 - 1);
        int d2 = man.getD2(i);
        if (d2 > 0) {
            ans[i + d2 - 1] = max(ans[i + d2 - 1], d2 * 2);
        }
    }
    for (int i = n - 1; i > 0; i--) {
        ans[i - 1] = max(ans[i - 1], ans[i] - 2);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
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