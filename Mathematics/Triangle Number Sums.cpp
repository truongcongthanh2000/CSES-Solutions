#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

vector<long long> triangles;
void init() {
    const long long LIM = 1e12;
    long long n = 1;
    while (n * (n + 1) / 2 <= LIM) {
        triangles.push_back(n * (n + 1) / 2);
        n++;
    }
}

void solve() {
    long long n;
    cin >> n;
    if (std::binary_search(triangles.begin(), triangles.end(), n)) {
        cout << 1 << '\n';
        return;
    }
    int R = triangles.size() - 1;
    for (int L = 0; L <= R; L++) {
        while (R >= L && triangles[L] + triangles[R] > n) R--;
        if (L <= R && triangles[L] + triangles[R] == n) {
            cout << 2 << '\n';
            return;
        }
    }
    cout << 3 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    init();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}