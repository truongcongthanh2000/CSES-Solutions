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
 
const int maxN = 2e5 + 100;
 
void sol() {
    long long n;
    int k;
    cin >> n >> k;
    vector<long long> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];
    long long ans = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        long long val = 1;
        int num = 0;
        for (int i = 0; i < k && val <= n; i++) {
            int bit = (mask >> i) & 1;
            if (bit) {
                num ^= 1;
                if (val > n / a[i]) {
                    val = n + 1;
                    break;
                }
                val *= a[i];
            }
        }
        if (val > n) continue;
        if (num) ans += n / val;
        else ans -= n / val;
    }
    cout << ans;
}
 
void solve() {
    clock_t begin = clock();
    int T;
   // cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ":" << ' ';
        //cout << "Test " << TestCase << ": ";
        sol();
    }
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << (double)(end - begin) / (double)CLOCKS_PER_SEC << '\n';
}
 
int main(int argc,char *argv[]) {
    ///srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}