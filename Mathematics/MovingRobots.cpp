#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const long long INF_LL = 1e18 + 100;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 30;
const long double EPS = 1e-9;
const int BLOCK = 1000;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

const int maxN = 2e6 + 10;

void sol() {
    int k;
    cin >> k;
    int n = 8;
    vector<vector<double> > res(n, vector<double>(n, 1.0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            vector<vector<double> > arr(n, vector<double>(n, 0.0));
            arr[i][j] = 1.0;
            for (int _ = 0; _ < k; ++_) {
                vector<vector<double> > tmp(n, vector<double>(n, 0.0));
                for (int x = 0; x < n; ++x) {
                    for (int y = 0; y < n; ++y) {
                        int num_direct = (x > 0) + (x < n - 1) + (y > 0) + (y < n - 1);
                        for (int h = 0; h < 4; h++) {
                            int u = x + dx[h];
                            int v = y + dy[h];
                            if (u >= 0 && u < n && v >= 0 && v < n) tmp[u][v] += arr[x][y] / num_direct;
                        }
                    }
                }
                swap(arr, tmp);
            }
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < n; ++y) res[x][y] *= 1.0 - arr[x][y];
            }
        }
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ans += res[i][j];
            //cout << res[i][j] << ' ';
        }
        //cout << '\n';
    }
    cout << fixed << setprecision(6) << ans;
}

void solve() {
    int T;
    //cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ":" << ' ';
        ///cout << "Case #" << TestCase << '\n';
        sol();
    }
}
int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}
