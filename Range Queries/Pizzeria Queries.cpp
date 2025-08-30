#pragma GCC diagnostic ignored "-Wunused-parameter"
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
 
using namespace std;
 
#define INP "solve"
#define OUT "solve"
 
const long long INF_LL = 1e17;
const int INF = 1e9 + 100;
const int MOD = 998244353;
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
 
class SegmentTree {
private:
    vector<int> IT;
    int n;
 
    void update(int i, int L, int R, int u, int val) {
        if (L > u || R < u) return;
        if (L == R) {
            IT[i] = val;
            return;
        }
        int mid = (L + R) >> 1;
        update(i << 1, L, mid, u, val);
        update(i << 1 | 1, mid + 1, R, u, val);
        IT[i] = min(IT[i << 1], IT[i << 1 | 1]);
    }
 
    int get(int i, int L, int R, int u, int v) {
        if (L > v || R < u) return INF_LL;
        if (L >= u && R <= v) return IT[i];
        int mid = (L + R) >> 1;
        int left = get(i << 1, L, mid, u, v);
        int right = get(i << 1 | 1, mid + 1, R, u, v);
        return min(left, right);
    }
public:
    SegmentTree(int _n = 1) {
        IT = vector<int>(_n * 4, 0);
        n = _n;
    }
    void update(int u, int val) {
        update(1, 0, n - 1, u, val);
    }
 
    int get(int L, int R) {
        return get(1, 0, n - 1, L, R);
    }
 
};
void sol() {
    int n, q;
    cin >> n >> q;
 
    SegmentTree mnL(n), mnR(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mnL.update(i, x - i);
        mnR.update(i, x + i);
    }
 
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, val;
            cin >> u >> val;
            u--;
            mnL.update(u, val - u);
            mnR.update(u, val + u);
        }
        else {
            int u;
            cin >> u;
            u--;
            int ans = mnL.get(0, u) + u;
            ans = min(ans, mnR.get(u + 1, n - 1) - u);
            cout << ans << '\n';
        }
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