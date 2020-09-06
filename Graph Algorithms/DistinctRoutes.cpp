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
const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int maxN = 3e5 + 100;
typedef pair<int, int> i2;
typedef pair<long long, int> i2LL;
typedef pair<long long, i2> i3;

struct Edge {
    int u, v;
    int c, f; ///if flow > int, use long long
    Edge(){};
    Edge(int _u, int _v, int _c, int _f) : u(_u), v(_v), c(_c), f(_f) {};
};
struct Ford_FulkersonFlow{ ///Base 0-th, The vertices are numbered from 0 to n - 1
    const int oo = 2e9; ///if flow > int, use long long
    vector <Edge> E;
    int n, numEdge;
    vector<vector<int> > adj; ///adj[u]: set index Edge u -> v
    vector<int> Trace_Edge; ///Trace_Edge[v]: index Edge u -> v in Argument Flow

    Ford_FulkersonFlow(int _n = 0) {
        n = _n; numEdge = 0;
        adj.resize(n);
        Trace_Edge.assign(n, -1);
    }

    void add_Edge(int u, int v, int c1, int c2) { ///if flow > int, use long long c1, c2
        ///u -> v: c1
        adj[u].push_back(numEdge);
        E.push_back(Edge(u, v, c1, 0));
        numEdge++;
        ///v -> u: c2
        adj[v].push_back(numEdge);
        E.push_back(Edge(v, u, c2, 0));
        numEdge++;
    }

    bool BFS(int s, int t) { ///check has path from s to t
        for (int i = 0; i < n; i++) Trace_Edge[i] = -1;
        queue <int> Q;
        Q.push(s);

        while ((int)Q.size() != 0) {
            int u = Q.front(); Q.pop();
            for (int id : adj[u]) {
                int v = E[id].v;
                if (E[id].f < E[id].c && Trace_Edge[v] == -1) {
                    Trace_Edge[v] = id; ///Trace_Edge[v] = index numberEdge: u -> v, be careful it's not v -> u
                    Q.push(v);
                    if (v == t) return true;
                }
            }
        }
        return false;
    }

    void ArgumentFlow(int s, int t) {
        int u = t;
        int Delta = oo;
        while (u != s) {
            int id = Trace_Edge[u];
            Delta = min(Delta, E[id].c - E[id].f);
            u = E[id].u;
        }
        u = t;
        while (u != s) {
            int id = Trace_Edge[u];
            E[id].f += Delta;
            E[id ^ 1].f -= Delta;
            u = E[id].u;
        }
    }

    void findPath(int u, vector<int> &res) {
        res.push_back(u);
        if (u == n - 1) {
            return;
        }
        for (int id : adj[u]) {
            if (E[id].f == E[id].c && E[id].f > 0) {
                int v = E[id].v;
                findPath(v, res);
                E[id].f = 0;
                return;
            }
        }
    }
    int maxFlow(int s, int t) {
        while (BFS(s, t)) ArgumentFlow(s, t);
        int ResFlow = 0;
        for (int id : adj[s])
            ResFlow += E[id].f;
        cout << ResFlow << '\n';
        for (int i = 0; i < ResFlow; i++) {
            vector<int> res;
            findPath(0, res);
            cout << (int)res.size() << '\n';
            for (int x : res) cout << x + 1 << ' ';
            cout << '\n';
        }
        return ResFlow;
    }

    int GetFlow(int idEdge) {
        return E[idEdge].f;
    }
};

void sol() {
    int n, m;
    cin >> n >> m;
    Ford_FulkersonFlow df(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        df.add_Edge(u, v, 1, 0);
    }
    cerr << df.maxFlow(0, n - 1) << '\n';
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
