#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

/*
The naive solution is sort coins[a..b] increasing and find the first element that > the prefix sum
    In case not found first element -> return total_sum + 1
Assume the answer is C, i is the largest so that 2^i < C -> sum all elements <= 2^i < C
    Build segment tree, every node is list 30 elements with element i is the smallest value in range [2^i - 2^(i+1))
    Build prefix sum 2D with prefix_sum[i] is prefix sum for all elements in range [2^i - 2^(i+1))
*/
const int INF = 1e9 + 100;
const int LG = 30;
struct Node {
    vector<int> values;
    Node() {
        values = vector<int>(LG, INF);
    }
};

Node combine(Node& left, const Node& right) {
    Node root;
    for (int i = 0; i < LG; i++) {
        root.values[i] = min(left.values[i], right.values[i]);
    }
    return root;
}

class FastSegmentTree {
   private:
    vector<Node> IT;
    int n;

   public:
    FastSegmentTree(int _n, const vector<int>& x) {
        n = _n;
        IT = vector<Node>(n * 2);
        for (int i = 0; i < n; i++) {
            int lg = __lg(x[i]);
            IT[i + n].values[lg] = x[i];
        }
        for (int i = n - 1; i > 0; --i) IT[i] = combine(IT[i << 1], IT[i << 1 | 1]);
    }

    // query on interval [l, r)
    Node get(int l, int r) {
        Node res;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = combine(res, IT[l++]);
            if (r & 1) res = combine(res, IT[--r]);
        }
        return res;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<long long>> prefix_sum(LG, vector<long long>(n, 0));
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        int lg = __lg(x[i]);
        prefix_sum[lg][i] = x[i];
    }
    FastSegmentTree st(n, x);
    for (int lg = 0; lg < LG; lg++) {
        for (int i = 1; i < n; i++) {
            prefix_sum[lg][i] = prefix_sum[lg][i] + prefix_sum[lg][i - 1];
        }
    }
    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        auto values = st.get(a, b + 1).values;
        long long sum = 0;
        for (int lg = 0; lg < LG; lg++) {
            if (sum + 1 < (1 << (lg + 1)) && sum + 1 < values[lg]) {
                break;
            }
            sum += prefix_sum[lg][b] - (a ? prefix_sum[lg][a - 1] : 0);
        }
        cout << sum + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}