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

const int maxN = 5e5 + 100;

template<typename T>
struct FenwickTree_2D{
    vector<vector<T> > fenwick;
    int N, M;
    FenwickTree_2D(){};
    FenwickTree_2D(int _N, int _M) {
        N = _N;
        M = _M;
        fenwick = vector<vector<T> >(N + 1, vector<T>(M + 1, 0));
    }

    void updateY(int x, int y, T val) {
        for (; y <= M; y += y & (-y)) fenwick[x][y] += val;
    }

    void updateX(int x, int y, T val) {
        for (; x <= N; x += x & (-x)) updateY(x, y, val);
    }

    T sumY(int x, int y) {
        T res = 0;
        for (; y; y -= y & (-y)) res += fenwick[x][y];
        return res;
    }
    T sumX(int x, int y) {
        T res = 0;
        for (; x; x -= x & (-x)) res += sumY(x, y);
        return res;
    }

    T get(int xL, int yL, int xR, int yR) {
        return sumX(xR, yR) - sumX(xL - 1, yR) - sumX(xR, yL - 1) + sumX(xL - 1, yL - 1);
    }
};

string s[maxN];
void sol() {
    int n, q;
    cin >> n >> q;
    FenwickTree_2D<int> fw_2D(n, n);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 1; j <= n; j++) {
            if (s[i][j - 1] == '*') fw_2D.updateX(i, j, 1);
            else fw_2D.updateX(i, j, 0);
        }
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            if (s[x][y - 1] == '*') {
                fw_2D.updateX(x, y, -1);
                s[x][y - 1] = '.';
            }
            else {
                fw_2D.updateX(x, y, 1);
                s[x][y - 1] = '*';
            }
        }
        else {
            int xL, yL, xR, yR;
            cin >> xL >> yL >> xR >> yR;
            cout << fw_2D.get(xL, yL, xR, yR) << '\n';
        }
    }
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
