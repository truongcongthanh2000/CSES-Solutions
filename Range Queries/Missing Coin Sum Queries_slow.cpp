#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

/*
The naive solution is sort coins[a..b] increasing and find the first element that > the prefix sum
    In case not found first element -> return total_sum + 1
Assume the answer is C, i is the largest so that 2^i < C -> sum all elements <= 2^i < C
    Build segment tree 2D, with segment_tree[i] store the smallest value in range [2^i - 2^(i+1))
    Build prefix sum 2D with prefix_sum[i] is prefix sum for all elements in range [2^i - 2^(i+1))
*/
const int INF = 1e9 + 100;

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
        for (IT[p += n] = val; p > 1; p >>= 1) IT[p >> 1] = min(IT[p], IT[p ^ 1]);
    }

    int query(int l, int r) {  // min on interval [l, r)
        int res = INF;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, IT[l++]);
            if (r & 1) res = min(res, IT[--r]);
        }
        return res;
    }
};
void solve() {
    const int LG = 30;
    int n, q;
    cin >> n >> q;
    vector<vector<long long>> prefix_sum(LG, vector<long long>(n, 0));
    vector<FastSegmentTree> st(30, FastSegmentTree(n, INF));
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int lg = __lg(x);
        prefix_sum[lg][i] = x;
        st[lg].modify(i, x);
    }
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
        long long sum = 0;
        for (int lg = 0; lg < 30; lg++) {
            if (sum + 1 < (1 << (lg + 1)) && sum + 1 < st[lg].query(a, b + 1)) {
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