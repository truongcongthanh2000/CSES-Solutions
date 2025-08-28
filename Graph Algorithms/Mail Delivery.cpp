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
typedef pair<long long, i2> i3;

vector<i2> adj[maxN];
int Used[maxN];
int h[maxN];
vector<int> eulerPath;
void DFS(int u) {
    ///must use &, if don't use & then it maybe TLE
    for (int &i = h[u]; i < (int)adj[u].size(); i++) {
        int v = adj[u][i].first;
        int id = adj[u][i].second;
        if (Used[id]++) continue;
        DFS(v);
    }
    eulerPath.push_back(u);
}

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    for (int i = 1; i <= n; i++) {
        if ((int)adj[i].size() % 2 == 1) {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    DFS(1);
    for (int i = 1; i <= m; i++) {
        if (Used[i] == 0) {
            cout << "IMPOSSIBLE";
            return;
        }
    }
    reverse(eulerPath.begin(), eulerPath.end());
    for (int x : eulerPath) cout << x << ' ';
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
