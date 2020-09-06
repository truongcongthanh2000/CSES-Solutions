#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const long long INF_LL = 1e17;
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

const int maxN = 2e6 + 100;

struct matrix {
    int c[6][6];
    matrix() {
        memset(c, 0, sizeof(c));
    }
};

matrix nhan(matrix a, matrix b) {
    matrix c;
    for (int k = 0; k < 6; k++) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 6; j++) {
                int cost = 1LL * a.c[i][k] * b.c[k][j] % MOD;
                c.c[i][j] = (c.c[i][j] + cost) % MOD;
            }
        }
    }
    return c;
}

matrix F(matrix a, long long n) {
    matrix res;
    for (int i = 0; i < 6; i++) res.c[i][i] = 1;
    for (; n; n >>= 1, a = nhan(a, a)) {
        if (n & 1) {
            res = nhan(res, a);
        }
    }
    return res;
}

void sol() {
    long long n;
    cin >> n;
    matrix a;
    for (int i = 1; i < 6; i++) a.c[i - 1][i] = 1;
    for (int i = 0; i < 6; i++) a.c[5][i] = 1;
    if (n <= 6) {
        cout << (1 << n - 1);
        return;
    }
    a = F(a, n - 6);
    int res = 0;
    for (int i = 0; i < 6; i++) {
        int cost = 1LL * (1 << i) * a.c[5][i] % MOD;
        res = (res + cost) % MOD;
    }
    cout << res;
}

void solve() {
    int T;
    ///cin >> T;
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
