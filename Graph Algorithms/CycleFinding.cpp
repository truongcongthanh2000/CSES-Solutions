#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const long long INF_LL = 1e15;
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
const int maxN = 5e3 + 100;
typedef pair<int, int> i2;
typedef pair<long long, int> i2LL;

vector<i2> adj[maxN];
long long dist[maxN];
int Trace[maxN];
int visit[maxN];

void sol() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++) dist[i] = INF_LL;
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int u = 1; u <= n; u++) {
            for (auto it : adj[u]) {
                int v = it.first;
                int w = it.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    Trace[v] = u;
                    if (i == n) {
                        cout << "YES" << '\n';
                        while (!visit[u]) {
                            visit[u] = 1;
                            u = Trace[u];
                        }
                        vector<int> res;
                        v = u;
                        res.push_back(v);
                        v = Trace[v];
                        while (u != v) {
                            res.push_back(v);
                            v = Trace[v];
                        }
                        res.push_back(v);
                        reverse(res.begin(), res.end());
                        for (int x : res) cout << x << ' ';
                        return;
                    }
                }
            }
        }
    }
    cout << "NO";
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
