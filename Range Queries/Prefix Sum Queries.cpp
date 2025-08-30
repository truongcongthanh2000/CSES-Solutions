#pragma GCC diagnostic ignored "-Wunused-parameter"
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
 
using namespace std;
 
#define INP "solve"
#define OUT "solve"
 
const long long INF_LL = 1e17;
const int INF = 1e9 + 100;
const int MOD = 998244353;
const int Base = 311;
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
 
const int maxN = 1e6 + 100;
 
struct Node {
    long long sum, pre;
    Node(long long _sum = 0, long long _pre = 0) {
        sum = _sum;
        pre = _pre;
    }
};
 
Node IT[maxN * 4];
Node Merge(Node Left, Node Right) {
    Node root;
    root.sum = Left.sum + Right.sum;
    root.pre = max(Left.pre, Left.sum + Right.pre);
    return root;
}
void update(int i, int L, int R, int u, int val) {
    if (L > u || R < u) return;
    if (L == R) {
        IT[i] = Node(val, val);
        return;
    }
    int mid = (L + R) >> 1;
    update(i << 1, L, mid, u, val);
    update(i << 1 | 1, mid + 1, R, u, val);
    IT[i] = Merge(IT[i << 1], IT[i << 1 | 1]);
}
 
Node get(int i, int L, int R, int u, int v) {
    if (L > v || R < u) return Node(0, -INF_LL);
    if (L >= u && R <= v) return IT[i];
    int mid = (L + R) >> 1;
    Node left = get(i << 1, L, mid, u, v);
    Node right = get(i << 1 | 1, mid + 1, R, u, v);
    return Merge(left, right);
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
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) update(1, 1, n, a, b);
        else cout << max(0LL, get(1, 1, n, a, b).pre) << '\n';
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