#pragma GCC diagnostic ignored "-Wunused-parameter"
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
 
using namespace std;
 
#define INP "solve"
#define OUT "solve"
 
const long long INF_LL = 8e18;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
//const int Base = 311;
const long double EPS = 1e-10;
const int BLOCK = 1000;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
 
void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}
 
const int maxN = 2e5 + 100;
 
struct CentroidDecomposition { //base 0th, 0 -> n � 1
//Centroid Tree, LCA(A, B) in normal tree  = LCA(A, B) in centroid tree
//max height: (logN)
    vector<set<int>> tree; // it's not vector<vector<int>>!
    vector<int> dad; ///dad[i] is parent node i in centroid tree, dad[root] = root
    vector<int> sub;
    int n;
 
    CentroidDecomposition(int _n = 0) {
        n = _n;
        tree.resize(n);
        dad.resize(n);
        sub.resize(n);
    }
 
    void addEdge(int u, int v) {
        tree[u].insert(v);
        tree[v].insert(u);
    }
 
    CentroidDecomposition(vector<set<int>> &tree) : tree(tree) {
        int n = tree.size();
        dad.resize(n);
        sub.resize(n);
        build(0, -1);
    }
 
    void build(int u, int p) { ///build centroid tree
        int n = dfs_subtree(u, p); // find the size of each subtree
 
        int centroid = dfs(u, p, n); // find the centroid
 
        if (p == -1) p = centroid; // dad of root is the root itself
        dad[centroid] = p;
 
        // for each tree resulting from the removal of the centroid
        for (auto v : tree[centroid]) {
            tree[v].erase(centroid), // the component from the tree
            build(v, centroid);
        }
        tree[centroid].clear();
    }
 
    int dfs_subtree(int u, int p) {
        sub[u] = 1;
        for (auto v : tree[u])
            if (v != p) sub[u] += dfs_subtree(v, u);
 
        return sub[u];
    }
    int dfs(int u, int p, int n) {
        for (auto v : tree[u])
            if (v != p && sub[v] > n/2) return dfs(v, u, n);
        return u;
    }
    int operator[](int i) {
        return dad[i];
    }
 
};
void sol() {
    int n;
    cin >> n;
    CentroidDecomposition CD(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        CD.addEdge(u, v);
    }
    CD.dfs_subtree(0, -1);
    cout << CD.dfs(0, -1, n) + 1;
}
 
void solve() {
    int T;
    //cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ":" << ' ';
        //cout << "Test " << TestCase << ": ";
        sol();
    }
}
 
int main(int argc,char *argv[]) {
    ///srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}