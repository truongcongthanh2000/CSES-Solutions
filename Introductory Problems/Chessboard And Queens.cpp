#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;

int x[10];
string s[10];
int h[10], c[10];
map<int, int> cheo;
int res = 0;
bool ok(int i, int j) {
    if (c[j]) return false;
    if (s[i][j] == '*') return false;
    for (int k = 1; k < i; k++) {
        if (abs(k - i) == abs(x[k] - j)) return false;
    }
    return true;
}
void vet(int i) {
    for (int j = 1; j <= 8; j++) {
        if (ok(i, j)) {
            c[j] = 1;
            x[i] = j;
            cheo[i - j] = 1;
            cheo[i + j] = 1;
            if (i == 8) res++;
            else vet(i + 1);
            c[j] = 0;
            cheo[i - j] = 0;
            cheo[i + j] = 0;
        }
    }
}
void solve() {
    for (int i = 1; i <= 8; i++) {
        cin >> s[i];
        s[i] = "0" + s[i];
    }
    vet(1);
    cout << res;
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
