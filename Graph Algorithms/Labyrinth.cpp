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
struct DisjointSetUnion { ///Base 1th or Base 0th
    ///if u is root then p[u] < 0 and |p[u]| is size of the Set that u is root
    ///if u is not root then p[u] = x and x, u are belong the same Set
    int n;
    vector <int> p;
    DisjointSetUnion(){};
    DisjointSetUnion(int _n) {
        n = _n;
        p.assign(n + 7, -1); ///p[i] = -1 for all i
    }

    int find_root(int u) { ///find the root in the Set contain u
        if (p[u] < 0) return u; ///u is root
        return p[u] = find_root(p[u]); ///get the root and jump
    }

    void Union(int u, int v) {
        int x = find_root(u);
        int y = find_root(v);
        if (x == y) return;
        if (p[x] > p[y]) swap(x, y); ///small Set point to big Set, p[x] > p[y] so |p[x]| < |p[y]|
        p[x] += p[y];
        p[y] = x;
    }

    bool sameSet(int u, int v) {
        return find_root(u) == find_root(v);
    }

    int numSet() {
        int res = 0;
        for (int i = 1; i <= n; i++) res += p[i] < 0;
        return res;
    }
};
string DIRECT = "URDL";
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int maxN = 1e3 + 100;
int n, m;
string s[maxN];
int dist[maxN][maxN];
int trace[maxN][maxN];

bool inSide(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
void getPath(int x, int y) {
    if (s[x][y] == 'A') return;
    int prev_h = (trace[x][y] + 2) % 4;
    int u = x + dx[prev_h];
    int v = y + dy[prev_h];
    getPath(u, v);
    cout << DIRECT[trace[x][y]];
}
void BFS(int xA, int yA) {
    queue<array<int, 2> > Q;
    dist[xA][yA] = 1;
    Q.push({xA, yA});
    while ((int)Q.size()) {
        int x = Q.front()[0];
        int y = Q.front()[1];
        Q.pop();
        for (int h = 0; h < 4; h++) {
            int u = x + dx[h];
            int v = y + dy[h];
            if (inSide(u, v) && s[u][v] != '#' && dist[u][v] == 0) {
                trace[u][v] = h;
                dist[u][v] = dist[x][y] + 1;
                Q.push({u, v});
                if (s[u][v] == 'B') {
                    cout << "YES" << '\n';
                    cout << dist[u][v] - 1 << '\n';
                    getPath(u, v);
                    return;
                }
            }
        }
    }
    cout << "NO";
}
void sol() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'A') {
                BFS(i, j);
                return;
            }
        }
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
