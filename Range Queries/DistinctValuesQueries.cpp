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

struct query {
    int L, R;
    int id;
    query(){};
    bool operator < (const query &A) {
        return R < A.R;
    }
};

int IT[maxN * 4];
void update(int i, int L, int R, int u, int val) {
    if (L > u || R < u) {
        return;
    }
    if (L == R) {
        IT[i] += val;
        return;
    }
    int mid = (L + R) >> 1;
    update(i << 1, L, mid, u, val);
    update(i << 1 | 1, mid + 1, R, u, val);
    IT[i] = IT[i << 1] + IT[i << 1 | 1];
}

int Get(int i, int L, int R, int u, int v) {
    if (L > v || R < u) {
        return 0;
    }
    if (L >= u && R <= v) {
        return IT[i];
    }
    int mid = (L + R) >> 1;
    int Left = Get(i << 1, L, mid, u, v);
    int Right = Get(i << 1 | 1, mid + 1, R, u, v);
    return Left + Right;
}

int x[maxN];
int res[maxN];
void sol() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> x[i];
    vector<query> Q(q);
    for (int i = 0; i < q; i++) {
        cin >> Q[i].L >> Q[i].R;
        Q[i].id = i;
    }
    sort(Q.begin(), Q.end());
    map<int, int> last;
    int R = 0;
    for (int i = 0; i < q; i++) {
        while (R < Q[i].R) {
            R++;
            update(1, 1, n, last[x[R]], -1);
            update(1, 1, n, R, 1);
            last[x[R]] = R;
        }
        res[Q[i].id] = Get(1, 1, n, Q[i].L, Q[i].R);
    }
    for (int i = 0; i < q; i++) cout << res[i] << '\n';
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
