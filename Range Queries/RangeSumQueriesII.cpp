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
struct FenwickTree{
    vector<T> fenwick;
    int N;
    FenwickTree(){};
    FenwickTree(int _N) {
        N = _N;
        fenwick = vector<T>(N + 1, 0);
    }

    void update(int x, T val) {
        for (; x <= N; x += x & (-x)) fenwick[x] += val;
    }

    T sum(int x) {
        T res = 0;
        for (; x; x -= x & (-x)) res += fenwick[x];
        return res;
    }

    T get(int L, int R) {
        return sum(R) - sum(L - 1);
    }
};
void sol() {
    int n, q;
    cin >> n >> q;
    FenwickTree<long long> fw(n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        fw.update(i, x);
    }
    while (q--) {
        int t, L, R;
        cin >> t >> L >> R;
        if (t == 1) {
            int x = fw.sum(L) - fw.sum(L - 1);
            fw.update(L, R - x);
        }
        else {
            cout << fw.get(L, R) << '\n';
        }
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
