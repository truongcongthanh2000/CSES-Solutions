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

void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}


string DIRECT = "URDL";
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int maxN = 3e5 + 100;
typedef pair<int, int> i2;
typedef pair<long long, int> i2LL;

vector<i2> adj[maxN];
int depth[maxN], inPath[maxN];
int Trace[maxN], Used[maxN];
void DFS(int u, int d) {
    depth[u] = d;
    inPath[u] = 1;
    for (auto [v, id]: adj[u]) {
        if (Used[id]++) continue;
        if (inPath[v]) {
            cout << depth[u] - depth[v] + 2 << '\n';
            vector<int> res;
            res.push_back(v);
            while (u != v) {
                res.push_back(u);
                u = Trace[u];
            }
            res.push_back(v);
            reverse(res.begin(), res.end());
            for (int x : res) cout << x << ' ';
            exit(0);
        }
        if (depth[v] == 0) {
            Trace[v] = u;
            DFS(v, d + 1);
        }
    }
    inPath[u] = 0;
}
void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
    }
    for (int i = 1; i <= n; i++) {
        if (depth[i] == 0) DFS(i, 1);
    }
    cout << "IMPOSSIBLE";
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

