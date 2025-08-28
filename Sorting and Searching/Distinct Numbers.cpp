#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> s(a.begin(), a.end());
    cout << (int)s.size();
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
