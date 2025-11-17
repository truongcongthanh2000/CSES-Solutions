#pragma GCC diagnostic ignored "-Wunused-parameter"
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
 
using namespace std;
 
#define INP "solve"
#define OUT "solve"
 
const long long INF_LL = 8e18;
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
 
int power(int a, long long n) {
    int ans = 1;
    for (; n; n >>= 1, a = 1LL * a * a % MOD) {
        if (n & 1) {
            ans = 1LL * ans * a % MOD;
        }
    }
    return ans;
}
 
int inverse(int a, int mod = MOD) {
    return power(a, mod - 2);
}
void sol() {
    int n;
    cin >> n;
    vector<pair<int, int> > p(n);
    for (int i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
 
    vector<int> pre_product(n), suf_product(n);
    pre_product[0] = p[0].second + 1;
    for (int i = 1; i < n; i++) pre_product[i] = 1LL * pre_product[i - 1] * (p[i].second + 1) % (MOD - 1);
    suf_product[n - 1] = p[n - 1].second + 1;
    for (int i = n - 2; i >= 0; i--) suf_product[i] = 1LL * suf_product[i + 1] * (p[i].second + 1) % (MOD - 1);
 
    int ans1 = 1;
    for (int i = 0; i < n; i++) ans1 = 1LL * ans1 * (p[i].second + 1) % MOD;
    cout << ans1 << ' ';
    {
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int cost = power(p[i].first, p[i].second + 1) - 1;
            cost = 1LL * cost * inverse(p[i].first - 1) % MOD;
            ans = 1LL * ans * cost % MOD;
        }
        cout << ans << ' ';
    }
    {
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int num = 1;
            if (i) num = pre_product[i - 1];
            if (i + 1 < n) num = 1LL * num * suf_product[i + 1] % (MOD - 1);
            int val = power(p[i].first, 1LL * p[i].second * (p[i].second + 1) / 2);
            int cost = power(val, num);
            ans = 1LL * ans * cost % MOD;
        }
        cout << ans << ' ';
    }
}
 
void solve() {
    clock_t begin = clock();
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
    clock_t end = clock();
    cerr << "Time: " << fixed << setprecision(10) << (double)(end - begin) / (double)CLOCKS_PER_SEC << '\n';
}
 
int main(int argc,char *argv[]) {
    ///srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}