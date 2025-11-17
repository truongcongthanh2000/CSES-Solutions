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

struct matrix {
    long long c[101][101];
    matrix() {
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) c[i][j] = INF_LL;
        }
    }
};

int n;
matrix nhan(matrix a, matrix b) {
    matrix c;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long cost = a.c[i][k] + b.c[k][j];
                c.c[i][j] = min(c.c[i][j], cost);
            }
        }
    }
    return c;
}

matrix F(matrix a, long long n) {
    matrix res;
    for (int i = 0; i < ::n; i++) res.c[i][i] = 0;
    for (; n; n >>= 1, a = nhan(a, a)) {
        if (n & 1) {
            res = nhan(res, a);
        }
    }
    return res;
}

void sol() {
    int m, k;
    cin >> n >> m >> k;
    matrix a;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        a.c[u][v] = min(a.c[u][v], 1LL * w);
    }
    a = F(a, k);
    if (a.c[0][n - 1] == INF_LL) cout << -1;
    else cout << a.c[0][n - 1];
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
