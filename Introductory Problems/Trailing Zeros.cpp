#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

//https://en.wikipedia.org/wiki/Legendre%27s_formula
int get(int n, int p) {
    int res = 0;
    int tmp = p;
    while (p <= n) {
        res += n / p;
        p *= tmp;
    }
    return res;
}
void solve() {
    int n;
    cin >> n;
    cout << min(get(n, 2), get(n, 5));
}

int main() {
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
