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
 
long long Mul(long long x, long long y,long long m) /// Tinh (x * y) mod M voi (x,y, M <= 10 ^ 18)
{
    x %= m; y %= m;
    long long q = (long double) x * y / m;
    long long r = (x * y - q * m) % m;
    if (r < 0) r += m;
    return r;
}
long long Pow(long long a, long long n, long long MOD) {
	long long ans = 1;
	for (; n; n >>= 1, a = Mul(a, a, MOD)) {
		if (n & 1) {
			ans = Mul(ans, a, MOD);
		}
	}
	return ans;
}
 
void sol() {
    int q; cin >> q;
    while (q--) {
        long long n, k; cin >> n >> k;
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        if (k <= n / 2) {
            cout << 2 * k << "\n";
            continue;
        }
        long long res = 2 * n + 1;
        long long tmp = 2 * n - 2 * k + 1;
        double x = (n < (2 * n - 2 * k + 1)) ? 0 : log2(1. * n / (2 * n - 2 * k + 1));
        long long e = floor(x) + 1;
        tmp *= Pow(2, e, (long long)(1e18));
        res -= tmp;
        long long d = (res - 1) / n;
        res -= d * n;
        assert(res >= 0 && res <= n);
        cout << res << '\n';
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