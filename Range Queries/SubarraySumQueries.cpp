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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

const int maxN = 5e5 + 100;

struct Node {
    long long res, sum, sumPrefix, sumSuffix;
    Node(){};
    Node(long long _res, long long _sum, long long _sumPrefix, long long _sumSuffix) {
        res = _res;
        sum = _sum;
        sumPrefix = _sumPrefix;
        sumSuffix = _sumSuffix;
    }
};

Node Merge(Node Left, Node Right) {
    Node root;
    root.sum = Left.sum + Right.sum;
    root.sumPrefix = max(Left.sumPrefix, Left.sum + Right.sumPrefix);
    root.sumSuffix = max(Right.sumSuffix, Right.sum + Left.sumSuffix);
    root.res = max(Left.res, Right.res);
    root.res = max(root.res, Left.sumSuffix + Right.sumPrefix);
    return root;
}

Node IT[maxN * 4];
void update(int i, int L, int R, int u, int val) {
    if (L > u || R < u) return;
    if (L == R) {
        IT[i] = Node(val, val, val, val);
        return;
    }
    int mid = (L + R) >> 1;
    update(i << 1, L, mid, u, val);
    update(i << 1 | 1, mid + 1, R, u, val);
    IT[i] = Merge(IT[i << 1], IT[i << 1 | 1]);
}

Node get(int i, int L, int R, int u, int v){
    if (L > v || R < u) return Node(-INF_LL, 0, -INF_LL, -INF_LL);
    if (L >= u && R <= v) return IT[i];
    int mid = (L + R) >> 1;
    Node Left = get(i << 1, L, mid, u, v);
    Node Right = get(i << 1 | 1, mid + 1, R, u, v);
    return Merge(Left, Right);
}

void sol() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }
    while (q--) {
        int k, x;
        cin >> k >> x;
        update(1, 1, n, k, x);
        cout << max(IT[1].res, 0LL) << '\n';
    }
}
void solve() {
    int T;
    ///cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ":" << ' ';
        ///cout << "Case #" << TestCase << '\n';
        sol();
    }
}

int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}
