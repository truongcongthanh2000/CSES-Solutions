//#pragma GCC diagnostic ignored "-Wunused-parameter"
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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
 
void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}
 
const int maxN = 1e7 + 100;
 
long long dp[20][10][2][2];
 
long long calc(long long n) {
    if (n < 10) return n + 1;
    vector<int> digits;
 
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
    memset(dp, -1, sizeof(dp));
 
    function<long long(int, int, bool, bool)> F = [&](int id, int pre_d, bool lower, bool leadZero) -> long long {
        if (id == (int)digits.size()) return 1;
        long long &ans = dp[id][pre_d][lower][leadZero];
        if (ans != -1)
            return ans;
 
        ans = 0;
        int limit_d = lower ? 9 : digits[id];
 
        for (int d = 0; d <= limit_d; d++) {
            bool nxt_lower = lower || (d < limit_d);
            bool nxt_leadZero = leadZero || (d > 0);
            if (d != pre_d || (leadZero == false && d == 0)) {
                ans += F(id + 1, d, nxt_lower, nxt_leadZero);
            }
        }
 
        return ans;
    };
 
    return F(0, 0, 0, 0);
}
 
void sol() {
    long long a, b;
    cin >> a >> b;
    cout << calc(b) - calc(a - 1);
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
    ///srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}