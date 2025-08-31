#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

const int maxN = 2e5 + 100;

void solve() {
    int n, k1, k2;
    cin >> n >> k1;
    k2 = k1;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto calc_sum = [&](deque<int> &suffix_sum, int p) {  // >= p
        if (p >= (int)suffix_sum.size()) return 0;
        return suffix_sum[max(0, p)];
    };
    long long ans = 0;
    auto combine = [&](deque<int> &small_ss, deque<int> &large_ss) {
        if (small_ss.size() > large_ss.size()) {
            swap(small_ss, large_ss);
        }
        for (int i = 0; i + 1 < small_ss.size(); i++) small_ss[i] -= small_ss[i + 1];
        for (int i = 0; i < small_ss.size(); i++) {
            int l = k1 - i, r = k2 - i + 1;  // >= l - >= r + 1
            int w = calc_sum(large_ss, l) - calc_sum(large_ss, r);
            ans += 1LL * small_ss[i] * w;
        }
        for (int i = small_ss.size() - 2; i >= 0; i--) small_ss[i] += small_ss[i + 1];
        for (int i = 0; i < small_ss.size(); i++) large_ss[i] += small_ss[i];
    };
    auto dfs = [&](auto &&self, int u, int pa) -> deque<int> {  // return suffix sum
        deque<int> prefix_sum{1};
        for (int v : adj[u]) {
            if (v != pa) {
                deque<int> sub_prefix_sum = self(self, v, u);
                sub_prefix_sum.push_front(sub_prefix_sum.front());  // add node u into the path
                combine(sub_prefix_sum, prefix_sum);
            }
        }
        return prefix_sum;
    };
    dfs(dfs, 0, -1);
    cout << ans << '\n';
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