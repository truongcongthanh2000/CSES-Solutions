#pragma GCC diagnostic ignored "-Wunused-parameter"
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
 
using namespace std;
 
#define INP "solve"
#define OUT "solve"
 
const long long INF_LL = 8e18;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
//const int Base = 311;
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
 
int fact[maxN];
void init() {
    fact[0] = 1;
    for (int i = 1; i < maxN; i++) fact[i] = 1LL * fact[i - 1] * i % MOD;
}
 
int power(int a, int n) {
    int ans = 1;
    for (; n; n >>= 1, a = 1LL * a * a % MOD) {
        if (n & 1) {
            ans = 1LL * ans * a % MOD;
        }
    }
    return ans;
}
 
int inverse(int a) {
    return power(a, MOD - 2);
}
 
int nCk(int n, int k) {
    if (n < k) return 0;
    int TS = fact[n];
    int MS = 1LL * fact[k] * fact[n - k] % MOD;
    return 1LL * TS * inverse(MS) % MOD;
}
 
int Catalan(int n) {
    int ans = nCk(2 * n, n);
    return 1LL * ans * inverse(n + 1) % MOD;
}
 
void sol() {
    int n;
    cin >> n;
    if (n & 1) cout << 0;
    else cout << Catalan(n / 2);
}
 
void solve() {
    init();
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