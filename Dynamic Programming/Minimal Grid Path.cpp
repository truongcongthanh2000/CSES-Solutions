#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> point;
#define x first
#define y second

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
        cin >> grid[i];

    vector<vector<bool>> vis(n, vector<bool>(n, false));

    vector<point> curr, next;
    for (curr.push_back({0, 0}); !curr.empty(); curr = next) {
        point p = curr.back();
        cout << grid[p.x][p.y];

        char mn = 'Z';
        for (point pt : curr) {
            int dx = 1, dy = 0;
            for (int i = 0; i < 2; ++i) {
                swap(dx, dy);
                int nx = pt.x + dx;
                int ny = pt.y + dy;
                if (nx >= n || ny >= n) continue;
                mn = min(mn, grid[nx][ny]);
            }
        }

        next.clear();
        for (point pt : curr) {
            int dx = 1, dy = 0;
            for (int i = 0; i < 2; ++i) {
                swap(dx, dy);
                int nx = pt.x + dx;
                int ny = pt.y + dy;
                if (nx >= n || ny >= n) continue;
                if (vis[nx][ny]) continue;
                if (grid[nx][ny] == mn) {
                    next.push_back({nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }
    }

    cout << endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}