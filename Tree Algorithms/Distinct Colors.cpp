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

int IT[maxN * 4];

void update(int i, int L, int R, int u, int val) {
    if (L > u || R < u) return;
    if (L == R) {
        IT[i] += val;
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
    int Left = get(i << 1, L, mid, u, v);
    int Right = get(i << 1 | 1, mid + 1, R, u, v);
    return Left + Right;
}

struct Query {
    int L, R, id;
    Query(){};
    Query(int _L, int _R, int _id) {
        L = _L;
        R = _R;
        id = _id;
    }
    bool operator < (const Query &A) {
        return R < A.R;
    }
};
Query q[maxN];
int c[maxN], a[maxN], res[maxN];
int last[maxN];
void sol() {
    int n;
    cin >> n;
    vector<int> nen;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        nen.push_back(c[i]);
    }
    sort(nen.begin(), nen.end());
    nen.resize(unique(nen.begin(), nen.end()) - nen.begin());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    for (int i = 1; i <= n; i++) {
        c[i] = lower_bound(nen.begin(), nen.end(), c[i]) - nen.begin();
        a[L[i]] = c[i];
        q[i] = Query(L[i], R[i], i);
    }
    sort(q + 1, q + 1 + n);
    int lastR = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = lastR + 1; j <= q[i].R; j++) {
            if (last[a[j]]) {
                update(1, 1, n, last[a[j]], -1);
            }
            update(1, 1, n, j, 1);
            last[a[j]] = j;
        }
        res[q[i].id] = get(1, 1, n, q[i].L, q[i].R);
        lastR = q[i].R;
    }
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
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
