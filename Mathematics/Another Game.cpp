#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int odd = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        odd |= x & 1;
    }
    if (odd)
        cout << "first" << '\n';
    else
        cout << "second" << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}