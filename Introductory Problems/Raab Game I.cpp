#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b; 
    int min_ab = min(a, b), max_ab = max(a, b);
    if (min_ab == 0 && max_ab > 0) {
        cout << "NO" << '\n';
        return;
    }
    if (min_ab + max_ab > n) {
        cout << "NO" << '\n';
        return;
    }
    vector<int> va, vb;
    for (int i = 1; i <= min_ab; i++) {
        va.push_back(i + max_ab);
        vb.push_back(i);
    }
    for (int i = 1; i <= max_ab; i++) {
        va.push_back(i);
        vb.push_back(i + min_ab);
    }
    for (int i = min_ab + max_ab + 1; i <= n; i++) {
        va.push_back(i);
        vb.push_back(i);
    }
    if (a > b) {
        swap(va, vb);
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) cout << va[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << vb[i] << ' ';
    cout << '\n';
}
int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}