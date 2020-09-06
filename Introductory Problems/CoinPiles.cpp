#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    if (a - b <= b && (a + b) % 3 == 0) {
        cout << "YES" << '\n';
    }
    else cout << "NO" << '\n';
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);
    #ifdef THEMIS
        freopen("solve.inp", "r", stdin);
        freopen("solve.out", "w", stdout);
    #endif // THEMIS
    int T;
    cin >> T;
    //T = 1;
    while (T--) solve();
}
