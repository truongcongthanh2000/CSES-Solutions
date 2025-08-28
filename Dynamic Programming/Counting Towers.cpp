#pragma GCC diagnostic ignored "-Wunused-parameter"
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
 
using namespace std;
 
#define INP "solve"
#define OUT "solve"
 
const long long INF_LL = 1e17;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 311;
const long double EPS = 1e-10;
const int BLOCK = 1000;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
 
void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}
 
const int maxN = 1e6 + 100;
 
int dp[maxN][2];
void sol() {
    const int limits = 1e6;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= limits; i++) {
        dp[i][0] = dp[i - 1][1];
        int cost = 1LL * dp[i - 1][0] * 4 % MOD;
        dp[i][0] = (dp[i][0] + cost) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i][1] + dp[i - 1][1]) % MOD;
    }
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
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
        //cout << "Test " << TestCase << ": ";
        sol();
    }
}
int main(int argc,char *argv[]) {
    ///srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}