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
 
int pw[maxN];
void init() {
    pw[0] = 1;
    for (int i = 1; i < maxN; i++) pw[i] = 1LL * pw[i - 1] * Base % MOD;
}
 
class SegmentTree{
private:
    vector<int> IT;
    int n;
 
    void update(int i, int L, int R, int u, char c) {
        if (L > u || R < u) return;
        if (L == R) {
            IT[i] = (int)c;
            return;
        }
        int mid = (L + R) >> 1;
        update(i << 1, L, mid, u, c);
        update(i << 1 | 1, mid + 1, R, u, c);
        IT[i] = (1LL * IT[i << 1] * pw[R - mid] + IT[i << 1 | 1]) % MOD;
    }
 
    int get(int i, int L, int R, int u, int v) {
        if (L > v || R < u) return 0;
        if (L >= u && R <= v) return IT[i];
        int mid = (L + R) >> 1;
        int left = get(i << 1, L, mid, u, v);
        int right = get(i << 1 | 1, mid + 1, R, u, v);
        return (1LL * left * pw[max(0, min(R, v) - mid)] + right) % MOD;
    }
public:
    SegmentTree(int _n = 0) {
        n = _n;
        IT = vector<int>(_n * 4, 0);
    }
 
    void up(int i, char c) {
        update(1, 0, n - 1, i, c);
    }
    int get(int L, int R) {
        return get(1, 0, n - 1, L, R);
    }
};
 
void sol() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<SegmentTree> st(2, SegmentTree(n));
 
    for (int i = 0; i < n; i++) {
        st[0].up(i, s[i]);
        st[1].up(n - i - 1, s[i]);
    }
    while (m--) {
        int t;
        cin >> t;
        if (t == 2) {
            int L, R;
            cin >> L >> R;
            L--; R--;
            int LR = st[0].get(L, R);
            int RL = st[1].get(n - R - 1, n - L - 1);
            if (LR == RL) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
        else {
            int i;
            char c;
            cin >> i >> c;
            i--;
            st[0].up(i, c);
            st[1].up(n - i - 1, c);
        }
    }
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