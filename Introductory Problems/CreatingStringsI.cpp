#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> res;
    do {
        res.push_back(s);
    }
    while (next_permutation(s.begin(), s.end()));
    cout << (int)res.size() << '\n';
    for (string s : res) cout << s << '\n';
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
