#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const long long INF_LL = 1e17;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 30;
const long double EPS = 1e-9;
const int BLOCK = 1000;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

const int maxN = 5e5 + 100;

long long IT[maxN * 4], lazy_value[maxN * 4];
int lazy[maxN * 4];
void app(int i, int L, int R, int lazy, long long val) {
    if (lazy == 1) { ///a[u] = val
        IT[i] = 0;
        lazy_value[i] = 0;
        ::lazy[i] = 1;
    }
    IT[i] += val * (R - L + 1);
    lazy_value[i] += val;
}
void push_down(int i, int L, int R) {
    //if (lazy[i] == 0) return;
    int mid = (L + R) >> 1;
    app(i << 1, L, mid, lazy[i], lazy_value[i]);
    app(i << 1 | 1, mid + 1, R, lazy[i], lazy_value[i]);
    lazy[i] = 0;
    lazy_value[i] = 0;
}
void update(int i, int L, int R, int u, int v, int val, int type) {
    if (L > v || R < u) return;
    if (L >= u && R <= v) {
        app(i, L, R, type, val);
        return;
    }
    int mid = (L + R) >> 1;
    push_down(i, L, R);
    update(i << 1, L, mid, u, v, val, type);
    update(i << 1 | 1, mid + 1, R, u, v, val, type);
    IT[i] = IT[i << 1] + IT[i << 1 | 1];
}

long long get(int i, int L, int R, int u, int v) {
    if (L > v || R < u) return 0;
    if (L >= u && R <= v) return IT[i];
    int mid = (L + R) >> 1;
    push_down(i, L, R);
    long long Left = get(i << 1, L, mid, u, v);
    long long Right = get(i << 1 | 1, mid + 1, R, u, v);
    return Left + Right;
}
void sol() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        update(1, 1, n, i, i, t, 1);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b, x;
            cin >> a >> b >> x;
            update(1, 1, n, a, b, x, 2);
        }
        if (t == 2) {
            int a, b, x;
            cin >> a >> b >> x;
            update(1, 1, n, a, b, x, 1);
        }
        if (t == 3) {
            int a, b;
            cin >> a >> b;
            cout << get(1, 1, n, a, b) << '\n';
        }
    }
}

void solve() {
    int T;
    ///cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ":" << ' ';
        ///cout << "Case #" << TestCase << '\n';
        sol();
    }
}

int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}
