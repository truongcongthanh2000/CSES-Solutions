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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

const int maxN = 3e5 + 100;

///SegmentTree Lazy
struct Node {
    long long sum, resmin, resmax;
    int id;
    Node(){};
    Node(long long _sum, long long _resmin, long long _resmax, int _id) {
        sum = _sum;
        resmin = _resmin;
        resmax = _resmax;
        id = _id;
    }
    bool operator < (const Node &A) const {
        if (resmin != A.resmin) return resmin < A.resmin;
        return id < A.id;
    }

    bool operator > (const Node &A) const {
        if (resmax != A.resmax) return resmax < A.resmax;
        return id > A.id;
    }
};

Node Merge(Node Left, Node Right) {
    Node res;
    res.sum = Left.sum + Right.sum;
    res.resmin = min(Left.resmin, Right.resmin);
    res.resmax = max(Left.resmax, Right.resmax);
    res.id = -1; ///add method if need track index
    return res;
}

struct SegmentTree{
    vector<Node> IT;
    vector<long long> lazy;
    int n;
    SegmentTree(int _n = 0) {
        n = _n;
        IT.resize(n * 4);
        lazy.resize(n * 4);
    }
    void build(int i, int L, int R) {
        IT[i] = Node(0, 0, 0, L);
        lazy[i] = 0;
        if (L == R) return;
        int mid = (L + R) >> 1;
        build(i << 1, L, mid);
        build(i << 1 | 1, mid + 1, R);
    }
    void cn(int i, int L, int R) {
        if (lazy[i] == 0) return;
        IT[i].resmin += lazy[i];
        IT[i].resmax += lazy[i];
        IT[i].sum += lazy[i] * (R - L + 1);
        if (L != R) {
            lazy[i << 1] += lazy[i];
            lazy[i << 1 | 1] += lazy[i];
        }
        lazy[i] = 0;
    }
    void add(int i, int L, int R, int u, int v, int val) {
        cn(i, L, R);
        if (L > v || R < u) return;
        if (L >= u && R <= v) {
            lazy[i] += val;
            cn(i, L, R);
            return;
        }
        int mid = (L + R) >> 1;
        add(i << 1, L, mid, u, v, val);
        add(i << 1 | 1, mid + 1, R, u, v, val);
        IT[i] = Merge(IT[i << 1], IT[i << 1 | 1]);
    }
    Node Get(int i, int L, int R, int u, int v) {
        cn(i, L, R);
        if (L > v || R < u) return Node(0, INF_LL, -INF_LL, -1);
        if (L >= u && R <= v) return IT[i];
        int mid = (L + R) >> 1;
        Node Left = Get(i << 1, L, mid, u, v);
        Node Right = Get(i << 1 | 1, mid + 1, R, u, v);
        return Merge(Left, Right);
    }

    void update(int L, int R, int val) {
        add(1, 1, n, L, R, val);
    }

    Node getNode(int L, int R) {
        return Get(1, 1, n, L, R);
    }
};
void sol() {
    int n, q;
    cin >> n >> q;
    SegmentTree st(n);
    st.build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        st.update(i, i, x);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int L, R, x;
            cin >> L >> R >> x;
            st.update(L, R, x);
        }
        else {
            int k;
            cin >> k;
            cout << st.getNode(k, k).resmin << '\n';
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
