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
int D[maxN];
int p[maxN][20];
void DFS(int u, int pa) {
    for (int i = 0; i < 20; i++) {
        int v = p[u][i];
        if (p[v][i] == 0) break;
        p[u][i + 1] = p[v][i];
    }
    for (int v : adj[u]) {
        if (v != pa) {
            p[v][0] = u;
            D[v] = D[u] + 1;
            DFS(v, u);
        }
    }
}

int LCA(int u, int v) {
    if (D[u] < D[v]) swap(u, v);
    int k = D[u] - D[v];
    for (int i = 19; i >= 0; i--) {
        if (k >= (1 << i)) {
            k -= (1 << i);
            u = p[u][i];
        }
    }
    if (u == v) return u;
    int res = 0;
    for (int i = 19; i >= 0; i--) {
        if (p[u][i] != p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
        else res = p[u][i];
    }
    return res;
}

int Dist(int a, int b) {
    int root = LCA(a, b);
    return D[a] + D[b] - 2 * D[root];
}
void sol() {
    int n, Q;
    cin >> n >> Q;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1, 0);
    while (Q--) {
        int a, b;
        cin >> a >> b;
        cout << Dist(a, b) << '\n';
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
