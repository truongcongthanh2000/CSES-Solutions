#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> occur(26, 0);
    for (char c : s) {
        occur[c - 'A']++;
    }
    int odd = 0;
    for (int i = 0; i < 26; i++) {
        odd += occur[i] % 2;
    }
    if (odd > 1) {
        cout << "NO SOLUTION";
        return;
    }
    for (int c = 0; c < 26; c++) {
        for (int i = 0; i < occur[c] / 2; i++) {
            cout << char(c + 'A');
        }
    }
    for (int c = 0; c < 26; c++) {
        if (occur[c] & 1) {
            cout << char(c + 'A');
        }
    }
    for (int c = 25; c >= 0; c--) {
        for (int i = 0; i < occur[c] / 2; i++) {
            cout << char(c + 'A');
        }
    }
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
