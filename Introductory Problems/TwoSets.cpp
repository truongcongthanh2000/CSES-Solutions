#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (1LL * n * (n + 1) / 2 % 2) {
        cout << "NO";
    }
    else {
        cout << "YES" << '\n';
        vector<int> a, b;
        if (n & 1) {
            for (int i = 1, j = n - 1; i <= j; i++, j--) {
                if (i & 1) {
                    a.push_back(i);
                    a.push_back(j);
                }
                else {
                    b.push_back(i);
                    b.push_back(j);
                }
            }
            b.push_back(n);
        }
        else {
            for (int i = 1, j = n; i <= j; i++, j--) {
                if (i & 1) {
                    a.push_back(i);
                    a.push_back(j);
                }
                else {
                    b.push_back(i);
                    b.push_back(j);
                }
            }
        }
        cout << (int)a.size() << '\n';
        for (int x : a) cout << x << ' ';
        cout << '\n';
        cout << (int)b.size() << '\n';
        for (int x : b) cout << x << ' ';
        cout << '\n';
    }
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
