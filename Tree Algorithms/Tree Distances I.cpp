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
int dist[3][maxN];

void BFS(int s, int n, int dist[maxN]) {
    for (int i = 1; i <= n; i++) dist[i] = -1;
    queue<int> Q;
    Q.push(s);
    dist[s] = 0;
    while ((int)Q.size() != 0) {
        int u = Q.front(); Q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
}

void sol() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    BFS(1, n, dist[0]);
    int u = max_element(dist[0] + 1, dist[0] + 1 + n) - dist[0];
    BFS(u, n, dist[1]);
    int v = max_element(dist[1] + 1, dist[1] + 1 + n) - dist[1];
    BFS(v, n, dist[2]);
    for (int i = 1; i <= n; i++) {
        cout << max(dist[1][i], dist[2][i]) << ' ';
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
