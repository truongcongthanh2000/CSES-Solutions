#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

const int maxN = 2e5 + 100;

vector<int> adj[maxN];

int order = 0, numNode[maxN];
int b[maxN][20], depth[maxN];
void DFS(int u, int pa) {
    for (int i = 0, lm = log2(depth[u] + 1); i <= lm; i++) {
        if (b[u][i] == 0) break;
        int v = b[u][i];
        b[u][i + 1] = b[v][i];
    }
    numNode[u] = 1;
    for (int v : adj[u]) {
        if (v != pa) {
            b[v][0] = u;
            depth[v] = depth[u] + 1;
            DFS(v, u);
            numNode[u] += numNode[v];
        }
    }
}

int LCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int k = depth[u] - depth[v];
    for (int i = (int)log2(depth[u] + 1); i >= 0; i--) {
        if (k >= (1 << i)) {
            u = b[u][i];
            k -= 1 << i;
        }
    }
    if (u == v) return u;
    int ans = 0;
    for (int i = (int)log2(depth[u] + 1); i >= 0; i--) {
        if (b[u][i] != b[v][i]) {
            u = b[u][i];
            v = b[v][i];
        } else
            ans = b[u][i];
    }
    return ans;
}

int chainHead[maxN], nChain = 1, chainInd[maxN], Pos[maxN], Base = 0;
void HLD(int u, int pa) {
    if (chainHead[nChain] == 0) {  /// chainHead[x] : đỉnh đầu tiên của đoạn thứ x
        chainHead[nChain] = u;
    }
    chainInd[u] = nChain;  /// đoạn mà chứa đỉnh u
    Pos[u] = ++Base;       /// Thứ tự của đỉnh u khi trải mảng

    int nxt = -1;
    for (int v : adj[u]) {
        if (v != pa) {
            if (nxt == -1 || numNode[v] > numNode[nxt]) nxt = v;  ////lấy đỉnh v có số nút con là max
        }
    }
    if (nxt != -1) HLD(nxt, u);

    for (int v : adj[u]) {
        if (v != nxt && v != pa) {
            nChain++;
            HLD(v, u);
        }
    }
}

class FastSegmentTree {
   private:
    vector<int> IT;
    int n;

   public:
    FastSegmentTree(int _n = 1, int _val = 0) {
        IT = vector<int>(_n * 2, _val);
        n = _n;
    }

    void modify(int p, int val) {
        for (IT[p += n] = val; p > 1; p >>= 1) IT[p >> 1] = max(IT[p], IT[p ^ 1]);
    }

    int query(int l, int r) {  // max on interval [l, r)
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, IT[l++]);
            if (r & 1) res = max(res, IT[--r]);
        }
        return res;
    }
};

int a[maxN];
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, 0);

    HLD(1, 0);

    FastSegmentTree fst(n);
    for (int i = 1; i <= n; i++) {
        fst.modify(Pos[i], a[i]);
    }
    auto getCost = [&](int u, int a) {  /// Tách đường đi từ u đến a: đỉnh u thuộc cây con gốc a
        // uchain chuỗi hiện tại của u
        // achain chuỗi của a
        int uchain = chainInd[u], achain = chainInd[a];
        int ans = 0;
        while (true) {
            if (uchain == achain) {
                int cost = fst.query(Pos[a], Pos[u] + 1);
                ans = max(ans, cost);
                break;
            }

            int cost = fst.query(Pos[chainHead[uchain]], Pos[u] + 1);
            ans = max(ans, cost);
            u = b[chainHead[uchain]][0];
            uchain = chainInd[u];
        }
        return ans;
    };

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            fst.modify(Pos[s], x);
        } else {
            int u, v;
            cin >> u >> v;
            int root = LCA(u, v);
            cout << max(getCost(u, root), getCost(v, root)) << ' ';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    clock_t start, end;
    start = clock();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    end = clock();
    cerr << "Time = " << (double)(end - start) / (double)CLOCKS_PER_SEC << '\n';
    return 0;
}