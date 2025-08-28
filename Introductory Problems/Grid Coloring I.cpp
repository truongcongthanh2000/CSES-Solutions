#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    /*
        ..x
        .y?
        Fill ? with diff x, y and original
    */ 
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            set<char> s;
            if (i) s.insert(grid[i - 1][j]);
            if (j) s.insert(grid[i][j - 1]);
            s.insert(grid[i][j]);
            for (char c = 'A'; c <= 'D'; c++) {
                if (!s.count(c)) {
                    grid[i][j] = c;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) cout << grid[i] << '\n';
}
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}