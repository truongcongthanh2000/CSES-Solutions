#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
 
using namespace std;
 
#define INP "solve"
#define OUT "solve"
 
const long long INF_LL = 4e18;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const long double EPS = 1e-10;
const int BLOCK = 550;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
 
void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}
const int maxN = 5e5 + 100;
 
void sol() {
    int m, n;
    cin >> m >> n;
    vector<vector<int> > dp(n + 1, vector<int>(1 << m, 0));
    dp[0][0] = 1;
 
    function<void(int, int, int, int)> calc = [&](int c, int r, int mask, int next_mask) {
        if (r == m) {
            dp[c + 1][next_mask] = (dp[c + 1][next_mask] + dp[c][mask]) % MOD;
        }
        else {
            if ((mask >> r) & 1) {
                calc(c, r + 1, mask, next_mask);
            }
            else {
                int cur_mask = 1 << r;
                calc(c, r + 1, mask, next_mask | cur_mask);
                if (r + 1 < m && !((mask >> (r + 1)) & 1)) {
                    calc(c, r + 2, mask, next_mask);
                }
            }
        }
    };
    for (int c = 0; c < n; c++) {
        for (int mask = 0; mask < (1 << m); mask++) {
            calc(c, 0, mask, 0);
        }
    }
    cout << dp[n][0] << '\n';
}
void solve() {
    clock_t begin = clock();
    int T;
    //cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ": ";
        //cout << "Test " << TestCase << ": ";
        sol();
        //if (T) cout << '\n';
    }
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << (double)(end - begin) / (double)CLOCKS_PER_SEC << '\n';
}
 
int main(int argc,char *argv[]) {
    ///srand(Time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}