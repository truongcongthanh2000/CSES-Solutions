#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

const int maxN = 2e5 + 100;
const long long INF_LL = 1e16;
struct Node {
    long long res, sum, sumPrefix, sumSuffix;
    Node() {};
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

Node get(int i, int L, int R, int u, int v) {
    if (L > v || R < u) return Node(-INF_LL, 0, -INF_LL, -INF_LL);
    if (L >= u && R <= v) return IT[i];
    int mid = (L + R) >> 1;
    Node Left = get(i << 1, L, mid, u, v);
    Node Right = get(i << 1 | 1, mid + 1, R, u, v);
    return Merge(Left, Right);
}

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(1, 1, n, i, x);
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        Node it = get(1, 1, n, a, b);
        cout << max(it.res, 0LL) << '\n';
    }
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}