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

vector<int> adj[maxN];
int L[maxN], R[maxN], order = 0;
void DFS(int u, int pa) {
    L[u] = ++order;
    for (int v : adj[u]) {
        if (v != pa) DFS(v, u);
    }
    R[u] = order;
}

long long IT[maxN * 4], lazy[maxN * 4];

void push_down(int i, int L, int R) {
    if (lazy[i] == 0) return;
    IT[i] += lazy[i] * (R - L + 1);
    if (L != R) {
        lazy[i << 1] += lazy[i];
        lazy[i << 1 | 1] += lazy[i];
    }
    lazy[i] = 0;
}

void update(int i, int L, int R, int u, int v, int val) {
    push_down(i, L, R);
    if (L > v || R < u) return;
    if (L >= u && R <= v) {
        lazy[i] = val;
        push_down(i, L, R);
        return;
    }
    int mid = (L + R) >> 1;
    update(i << 1, L, mid, u, v, val);
    update(i << 1 | 1, mid + 1, R, u, v, val);
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

int v[maxN];
void sol() {
    int n, Q;
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    for (int i = 1; i <= n; i++) update(1, 1, n, L[i], R[i], v[i]);
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            int old_v = v[s];
            update(1, 1, n, L[s], R[s], x - old_v);
            v[s] = x;
        }
        else {
            int s;
            cin >> s;
            cout << get(1, 1, n, L[s], L[s]) << '\n';
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
