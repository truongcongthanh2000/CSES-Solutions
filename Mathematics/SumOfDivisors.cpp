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

const int maxN = 1e6 + 100;

int get(long long n) {
    n %= MOD;
    int res = n * (n + 1) % MOD;
    res = 1LL * res * (MOD + 1) / 2 % MOD;
    return res;
}
void sol() {
    long long n;
    cin >> n;
    int x = sqrt(n);
    int res = 0;
    for (long long i = 1; i <= n; i = n / (n / (i + 1))) {
        long long a = n / (i + 1);
        long long b = n / i;
        int cost = (get(b) - get(a) + MOD) % MOD;
        cost = 1LL * cost * i % MOD;
        res = (res + cost) % MOD;
        if (i == n) break;
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
