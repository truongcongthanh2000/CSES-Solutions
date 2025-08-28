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

struct DisjointSetUnion { ///Base 1th or Base 0th
    ///if u is root then p[u] < 0 and |p[u]| is size of the Set that u is root
    ///if u is not root then p[u] = x and x, u are belong the same Set
    int n;
    vector <int> p;
    multiset<int> components;
    DisjointSetUnion(){};
    DisjointSetUnion(int _n) {
        n = _n;
        p.assign(n + 7, -1); ///p[i] = -1 for all i
        for (int i = 0; i < n; i++) components.insert(1);
    }

    int find_root(int u) { ///find the root in the Set contain u
        if (p[u] < 0) return u; ///u is root
        return p[u] = find_root(p[u]); ///get the root and jump
    }

    bool Union(int u, int v) {
        int x = find_root(u);
        int y = find_root(v);
        if (x == y) return false;
        components.erase(components.find(abs(p[x])));
        components.erase(components.find(abs(p[y])));
        if (p[x] > p[y]) swap(x, y); ///small Set point to big Set, p[x] > p[y] so |p[x]| < |p[y]|
        p[x] += p[y];
        p[y] = x;
        components.insert(abs(p[x]));
        return true;
    }

    bool sameSet(int u, int v) {
        return find_root(u) == find_root(v);
    }

    int numSet() {
        return (int)components.size();
    }
    int largestSize() {
        return *components.rbegin();
    }
};

void sol() {
    int n, m;
    cin >> n >> m;
    DisjointSetUnion df(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        df.Union(u, v);
        cout << df.numSet() << ' ' << df.largestSize() << '\n';
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
