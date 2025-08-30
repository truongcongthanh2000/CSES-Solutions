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

int lazy[maxN * 4];
long long lazy_sum[maxN * 4], IT[maxN * 4];
long long get(int L, int R) {
    long long n = (R - L + 1);
    return n * L + n * (n - 1) / 2;
}

void push_down(int i, int L, int R) {
    IT[i] += get(L, R) * lazy[i];
    IT[i] += lazy_sum[i] * (R - L + 1);
    int mid = (L + R) >> 1;
    if (L != R) {
        lazy[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i];
        lazy_sum[i << 1] += lazy_sum[i];
        lazy_sum[i << 1 | 1] += lazy_sum[i];
    }
    lazy[i] = 0;
    lazy_sum[i] = 0;
}

void update(int i, int L, int R, int u, int v, int val, int number) {
    push_down(i, L, R);
    if (L > v || R < u) return;
    if (L >= u && R <= v) {
        lazy_sum[i] = val;
        lazy[i] = number;
        push_down(i, L, R);
        return;
    }
    int mid = (L + R) >> 1;
    update(i << 1, L, mid, u, v, val, number);
    update(i << 1 | 1, mid + 1, R, u, v, val, number);
    IT[i] = IT[i << 1] + IT[i << 1 | 1];
}

long long get(int i, int L, int R, int u, int v) {
    push_down(i, L, R);
    if (L > v || R < u) return 0;
    if (L >= u && R <= v) return IT[i];
    int mid = (L + R) >> 1;
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
        update(1, 1, n, i, i, t, 0);
    }
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) update(1, 1, n, a, b, 1 - a, 1);
        else cout << get(1, 1, n, a, b) << '\n';
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
