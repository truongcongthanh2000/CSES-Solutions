#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};

void solve() {
    int n;
    cin >> n;
    queue<pair<int, int>> Q;
    vector<vector<int>> d(n, vector<int>(n, -1));
    Q.push({0, 0});
    d[0][0] = 0;
    while (Q.size() != 0) {
        pair<int, int> it = Q.front(); Q.pop();
        int x = it.first, y = it.second;
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && d[nx][ny] == -1) {
                d[nx][ny] = d[x][y] + 1;
                Q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << d[i][j] << ' ';
        cout << '\n';
    }
}
int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}