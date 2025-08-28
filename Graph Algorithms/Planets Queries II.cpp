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

vector<int> adj[maxN];
int t[maxN];
int L[maxN], R[maxN], order = 0;
int dist[maxN];
int root[maxN];
int sizeCycle[maxN];
int Used[maxN];
int Trace[maxN];
int pos_Cycle[maxN];

void DFS(int u) {
    L[u] = ++order;
    for (int v : adj[u]) {
        if (Trace[v] != v) { ///v is not belong cycle
            dist[v] = dist[u] + 1;
            root[v] = root[u];
            Trace[v] = Trace[u];
            DFS(v);
        }
    }
    R[u] = order;
}

void sol() {
    int n, Q;
    cin >> n >> Q;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        adj[t[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (L[i]) continue;
        int u = i;
        while (Used[u] == 0) {
            Used[u] = 1;
            u = t[u];
        }
        vector<int> cycle;
        while (cycle.empty() || u != cycle[0]) {
            pos_Cycle[u] = (int)cycle.size();
            cycle.push_back(u);
            root[u] = i;
            Trace[u] = u;
            u = t[u];
        }
        for (int x : cycle) {
            order = 0;
            DFS(x);
            sizeCycle[x] = (int)cycle.size();
        }
    }
    while (Q--) {
        int a, b;
        cin >> a >> b;
        int ans = -1;
        if (root[a] == root[b]) {
            if (Trace[b] == b) {
                ans = dist[a];
                a = Trace[a];
                ans += (pos_Cycle[b] - pos_Cycle[a] + sizeCycle[a]) % sizeCycle[a];
            }
            else {
                if (Trace[a] == Trace[b] && L[b] <= L[a] && R[b] >= R[a]) {
                    ans = dist[a] - dist[b];
                }
            }
        }
        cout << ans << '\n';
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

