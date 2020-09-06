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

struct DinicFlow {
    int n;
    int numEdge = 0;
    vector<int> head, work, dist;
    vector<int> points, next;
    vector<int> flow, cap;

    DinicFlow(int _n = 0) {
        numEdge = 0;
        n = _n;
        head.assign(n + 7, -1);
        dist.assign(n + 7, -1);
        work.assign(n + 7, -1);
    }
    void addEdge(int u, int v, int c1, int c2) {
        ///u -> v
        points.push_back(v); flow.push_back(0); cap.push_back(c1); next.push_back(head[u]); head[u] = numEdge++;
        ///v -> u
        points.push_back(u); flow.push_back(0); cap.push_back(c2); next.push_back(head[v]); head[v] = numEdge++;
    }

    bool BFS(int s, int t) {
        for (int i = 0; i <= n; i++) dist[i] = -1;
        dist[s] = 0;
        queue<int> Q;
        Q.push(s);
        while ((int)Q.size()) {
            int u = Q.front(); Q.pop();
            for (int i = head[u]; i >= 0; i = next[i]) {
                int v = points[i];
                if (flow[i] < cap[i] && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    if (v == t) return true;
                    Q.push(v);
                }
            }
        }
        return false;
    }

    int DFS(int s, int t, int f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = next[i]) {
            int v = points[i];
            if (flow[i] < cap[i] && dist[v] == dist[s] + 1) {
                int delta = DFS(v, t, min(f, cap[i] - flow[i]));
                if (delta != INF) {
                    flow[i] += delta;
                    flow[i ^ 1] -= delta;
                    return delta;
                }
            }
        }
        return INF;
    }

    long long maxFlow(int s, int t) {
        long long res = 0;
        while (BFS(s, t)) {
            for (int i = 0; i <= n; i++) work[i] = head[i];
            while (true) {
                int delta = DFS(s, t, INF);
                if (delta == INF) break;
                res += delta;
            }
        }
        return res;
    }
    void MinCut(int s) {
        vector <int> Pos;
        for (int i = 0; i <= n; i++) dist[i] = -1;
        dist[s] = 0;
        queue <int> Q;
        Q.push(s);
        while (Q.size() != 0) {
            int u = Q.front(); Q.pop();
            Pos.push_back(u);
            for (int i = head[u]; i >= 0; i = next[i]) {
                int v = points[i];
                if (flow[i] < cap[i] && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }
            }
        }
        vector<pair<int, int> > res;
        for (int u : Pos) {
            for (int i = head[u]; i >= 0; i = next[i]) {
                int v = points[i];
                if (flow[i] == cap[i] && find(Pos.begin(), Pos.end(), v) == Pos.end()) {
                    res.push_back({u, v});
                }
            }
        }
        cout << (int)res.size() << '\n';
        for (auto it : res) cout << it.first << " " << it.second << '\n';
    }
};

void sol() {
    int n, m;
    cin >> n >> m;
    DinicFlow df(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        df.addEdge(u, v, 1, 1);
    }
    cerr << df.maxFlow(1, n) << '\n';
    df.MinCut(1);
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
