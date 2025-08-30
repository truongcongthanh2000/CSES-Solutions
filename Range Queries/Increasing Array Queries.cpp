#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    /*
        The answer of query a, b = sum(max(x[a..i]) - x[i]), for i in [a, b]
                                 = sum(max(x[a..i])) - sum(x[i]) for i in [a, b]
        Given r[i] = smallest j > i that x[j] > x[i]
            sum(max(x[a..i])) = sum(x[a] * (r[a] - a) + x[r[a]] * (r[r[a]] - r[a]) ...) + min(x[...] * (min(b, r[...]) - ...))
        For each position i, we only need to care r[i], so we can create suffix sum* to calc sum(x[a] * (r[a] - a) + x[r[a]] * (r[r[a]] - r[a])) ..
        In each query, find max position when jump p = r[p], start from a <= b
        The answer = (suffix_sum[a] - suffix_sum[p]) + x[p] * (b - p)

    */
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<long long> prefix_sum(n, 0);
    prefix_sum[0] = x[0];
    for (int i = 1; i < n; i++) prefix_sum[i] = prefix_sum[i - 1] + x[i];

    vector<vector<int>> queries(q, vector<int>(3, 0));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
        queries[i][0]--;
        queries[i][1]--;
        queries[i][2] = i;
    }
    sort(queries.begin(), queries.end());
    vector<long long> answer(q);
    vector<long long> suffix_sum(n + 1, 0);
    vector<int> stk;
    int j = q - 1;
    for (int i = n - 1; i >= 0; i--) {
        while (stk.size() > 0 && x[i] >= x[stk.back()]) {
            stk.pop_back();
        }
        int r = stk.empty() ? n : stk.back();
        suffix_sum[i] = 1LL * x[i] * (r - i) + suffix_sum[r];
        stk.push_back(i);
        while (j >= 0 && queries[j][0] == i) {
            int a = queries[j][0], b = queries[j][1], idx = queries[j][2];
            int p = *--upper_bound(stk.rbegin(), stk.rend(), b);
            answer[idx] = suffix_sum[i] - suffix_sum[p];
            answer[idx] += 1LL * x[p] * (b - p + 1);
            answer[idx] -= prefix_sum[b] - (a ? prefix_sum[a - 1] : 0);
            j--;
        }
    }
    for (int i = 0; i < q; i++) cout << answer[i] << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}