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

struct MaxBipartiteMatching { ///base 1th; X -> Y
    int n, m;
    vector <int> link, match, stk, Used;
    bool Found;
    vector <vector<int> > adj;
    MaxBipartiteMatching(){};
    MaxBipartiteMatching(int _n, int _m) {
        n = _n; ///Size(X)
        m = _m; ///Size(Y)
        link.assign(n + 7, 0); ///X
        match.assign(m + 7, 0); ///match[y] = x, if have x -> y in MaxBipartiteMatching or 0 if not
        Used.assign(m + 7, 0);
        stk.clear();
        adj.resize(n + 7);
    }

    void addEdge(int u, int v) { ///u in X and v in Y
        adj[u].push_back(v);
    }

    void DFS(int u) {
        for (int v : adj[u]) {
            if (Used[v] == 0) {
                Used[v] = 1;
                stk.push_back(v);
                if (match[v] == 0) Found = true;
                else DFS(match[v]);
                if (Found) {
                    match[v] = u;
                    return;
                }
            }
        }
    }

    int getCost() { ///get size MaxBipartiteMatching
        int Nlink = n;
        for (int i = 1; i <= n; i++) link[i] = i;
        for (int i = 1; i <= m; i++) match[i] = 0;
        int old;
        do {
            old = Nlink;
            for (int x : stk) Used[x] = 0;
            stk.clear();
            for (int i = Nlink; i >= 1; i--) {
                Found = false;
                DFS(link[i]);
                if (Found) {
                    link[i] = link[Nlink--];
                }
            }
        }
        while (old != Nlink);
        return n - old;
    }

    int getX(int y) { ///match[y] = x, if have x -> y in MaxBipartiteMatching or 0 if not
        return match[y];
    }
};


void sol() {
    int n, m, k;
    cin >> n >> m >> k;
    MaxBipartiteMatching df(n, m);
    for (int i = 1; i <= k; i++) {
        int u, v;
        cin >> u >> v;
        df.addEdge(u, v);
    }
    cout << df.getCost() << '\n';
    for (int i = 1; i <= m; i++) {
        int j = df.getX(i);
        if (j != 0) cout << j << " " << i << '\n';
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
