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

vector<int> adj[maxN];
int inDeg[maxN];
int dp[maxN];
int Trace[maxN];

void getPath(int u) {
    if (u == 0) return;
    getPath(Trace[u]);
    cout << u << ' ';
}

vector<int> order;
int Used[maxN];
void DFS(int u) {
    Used[u] = 1;
    for (int v : adj[u]) {
        if (Used[v] == 0) DFS(v);
    }
    order.push_back(u);
}
void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDeg[v]++;
    }
    DFS(1);
    reverse(order.begin(), order.end());
    for (int i = 1; i <= n; i++) {
        dp[i] = -1;
    }
    dp[1] = 1;
    for (int u : order) {
        for (int v : adj[u]) {
            if (dp[v] < dp[u] + 1) {
                dp[v] = dp[u] + 1;
                Trace[v] = u;
            }
        }
    }
    if (dp[n] <= 0) {
        cout << "IMPOSSIBLE" << '\n';
    }
    else {
        cout << dp[n] << '\n';
        getPath(n);
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

