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
int eu[maxN], ev[maxN];
vector<int> eulerPath;
void DFS(int u) {
    ///must use &, if don't use & then it maybe TLE
    for (int &i = h[u]; i < (int)adj[u].size(); i++) {
        int v = adj[u][i].first;
        int id = adj[u][i].second;
        if (Used[id]++) continue;
        DFS(eu[id] ^ ev[id] ^ u);
        eulerPath.push_back(id);
    }
    //eulerPath.push_back(u);
}

void sol() {
    int n;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        ///i = 11001
        ///u = 1100
        ///v = 1001
        ///i ^ u ^ v =
        int u = i / 2;
        int v = i & ((1 << (n - 1)) - 1);
        eu[i] = u;
        ev[i] = v;
        adj[v].push_back({i, i});
    }
    DFS(0);
    reverse(eulerPath.begin(), eulerPath.end());
    for (int x : eulerPath) cout << x % 2;
    for (int i = 0; i < n - 1; i++) cout << 0;
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
