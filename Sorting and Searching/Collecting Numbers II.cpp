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
 
int tmp[maxN];
pair<int, int> x[maxN];
void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> x[i].first;
        x[i].second = i;
        tmp[i] = x[i].first;
    }
    sort(x + 1, x + 1 + n);
    auto weak = [&](int i) {
        return i >= 1 && i < n && x[i].second > x[i + 1].second;
    };
    int ans = 1;
    for (int i = 1; i < n; i++) ans += weak(i);
    while (m--) {
        int a, b;
        cin >> a >> b;
        int xa = tmp[a], xb = tmp[b];
        if (xa > xb) swap(xa, xb);
        ans -= weak(xa - 1);
        if (xb != xa + 1)ans -= weak(xb - 1);
        ans -= weak(xa);
        if (xb != xa) ans -= weak(xb);
        swap(tmp[a], tmp[b]);
        swap(x[xa].second, x[xb].second);
        ans += weak(xa - 1);
        if (xb != xa + 1) ans += weak(xb - 1);
        ans += weak(xa);
        if (xb != xa) ans += weak(xb);
        cout << ans << '\n';
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