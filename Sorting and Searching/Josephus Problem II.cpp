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
 
int IT[maxN * 4];
 
void update(int i, int L, int R, int u, int val) {
    if (L > u || R < u) return;
    if (L == R) {
        IT[i] = val;
        return;
    }
    int mid = (L + R) >> 1;
    update(i << 1, L, mid, u, val);
    update(i << 1 | 1, mid + 1, R, u, val);
    IT[i] = IT[i << 1] + IT[i << 1 | 1];
}
 
int get(int i, int L, int R, int u, int v) {
    if (L > v || R < u) return 0;
    if (L >= u && R <= v) return IT[i];
    int mid = (L + R) >> 1;
    int left = get(i << 1, L, mid, u, v);
    int right = get(i << 1 | 1, mid + 1, R, u, v);
    return left + right;
}
 
int find_pos(int i, int L, int R, int k) {
    if (IT[i] < k) return -1;
    if (L == R) return L;
    int mid = (L + R) >> 1;
    if (IT[i << 1] < k) return find_pos(i << 1 | 1, mid + 1, R, k - IT[i << 1]);
    return find_pos(i << 1, L, mid, k);
}
void sol() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) update(1, 1, n, i, 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int steps = k % (n - i + 1) + 1;
        int remain = get(1, 1, n, ans + 1, n);
        if (steps <= remain) {
            int pre = get(1, 1, n, 1, ans);
            ans = find_pos(1, 1, n, steps + pre);
        }
        else {
            steps -= remain;
            ans = find_pos(1, 1, n, steps);
        }
        assert(ans >= 1 && ans <= n && get(1, 1, n, ans, ans) == 1);
        update(1, 1, n, ans, 0);
        cout << ans << ' ';
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