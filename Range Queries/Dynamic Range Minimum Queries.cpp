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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()); //comment this in SCPC
mt19937_64 rnd_64(chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

const int maxN = 3e5 + 100;

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
    IT[i] = min(IT[i << 1], IT[i << 1 | 1]);
}

int get(int i, int L, int R, int u, int v) {
    if (L > v || R < u) return INF;
    if (L >= u && R <= v) return IT[i];
    int mid = (L + R) >> 1;
    int Left = get(i << 1, L, mid, u, v);
    int Right = get(i << 1 | 1, mid + 1, R, u, v);
    return min(Left, Right);
}
void sol() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }
    while (q--) {
        int t, L, R;
        cin >> t >> L >> R;
        if (t == 1) {
            update(1, 1, n, L, R);
        }
        else {
            cout << get(1, 1, n, L, R) << '\n';
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
        sol();
    }
}

int main(int argc,char *argv[]) {
    ///srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}
