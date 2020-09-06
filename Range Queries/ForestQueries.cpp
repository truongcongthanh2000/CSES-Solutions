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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()); //comment this in SCPC
mt19937_64 rnd_64(chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

const int maxN = 3e5 + 100;

template<typename T>
struct sum_2D {
    int n, m;
    vector<vector<T> > a;
    sum_2D(int _n, int _m) {
        n = _n;
        m = _m;
        a = vector<vector<T> >(n + 1, vector<T>(m + 1, 0));
    }

    void set_value(int x, int y, T value) {
        a[x][y] = value;
    }

    void precalc() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) a[i][j] += a[i - 1][j]  + a[i][j - 1] - a[i - 1][j - 1];
        }
    }

    T get(int xL ,int yL, int xR, int yR) {
        return a[xR][yR] - a[xL - 1][yR] - a[xR][yL - 1] + a[xL - 1][yL - 1];
    }
};
void sol() {
    int n, q;
    cin >> n >> q;
    sum_2D<int> s(n, n);
    for (int i = 1; i <= n; i++) {
        string forest;
        cin >> forest;
        for (int j = 1; j <= n; j++) {
            if (forest[j - 1] == '*') s.set_value(i, j, 1);
            else s.set_value(i, j, 0);
        }
    }
    s.precalc();
    while (q--) {
        int xL, yL, xR, yR;
        cin >> xL >> yL >> xR >> yR;
        cout << s.get(xL, yL, xR, yR) << '\n';
    }
}
void solve() {
    int T;
    //cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ":" << ' ';
        sol();
    }
}

int main(int argc,char *argv[]) {
    ///srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}
