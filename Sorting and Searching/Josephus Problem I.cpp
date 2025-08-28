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
 
int nxt[maxN];
int find_root(int u) {
    return nxt[u] == u ? u : nxt[u] = find_root(nxt[u]);
}
 
void del(int u) {
    nxt[u] = find_root(u + 1);
}
void sol() {
    int n, k = 2;
    cin >> n;
    nxt[0] = 1, nxt[n + 1] = 0;
    for (int i = 1; i <= n; i++) nxt[i] = i;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int t = 0; t < k; t++) {
            ans = find_root(ans + 1);
        }
        cout << ans << ' ';
        del(ans);
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