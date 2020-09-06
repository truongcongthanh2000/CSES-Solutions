#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const int maxP = 1e4 + 10;
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

int power(int a, int n) {
    int res = 1;
    for (; n; n >>= 1, a = 1LL * a * a % MOD) {
        if (n & 1) res = 1LL * res * a % MOD;
    }
    return res;
}

int inverse(int a) {
    return power(a, MOD - 2);
}

void Minimize(int &a, int b) {
    a = min(a, b);
}

void Maximize(int &a, int b) {
    a = max(a, b);
}

void mul(int &a, int b) {
    a = 1LL * a * b % MOD;
}

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void sub(int &a, int b) {
    a -= b;
    if (a < 0) a += MOD;
}

const int maxN = 3e5 + 10;
const int maxM = 110;

array<int, 3> a[maxN];
void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    sort(a + 1, a + 1 + n, [&](array<int, 3> a, array<int, 3> b) {
        if (a[1] != b[1]) return a[1] < b[1];
        if (a[0] < b[0]) return a[0] < b[0];
        return a[2] < b[2];
    });
    set<array<long long, 2> > dp;
    dp.insert({0, 0});
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        auto it = dp.lower_bound({a[i][0], -1});
        it--;
        res = max(res, (*it)[1] + a[i][2]);
        dp.insert({a[i][1], res});
    }
    cout << res;
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
