#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

/*
Given an array x of n integers, your task is to process q queries of the form:
how many integers i satisfy a <= i <= b and c <= x_i <= d?
*/
template <typename T>
struct FenwickTree {
    vector<T> fenwick;
    int N;
    FenwickTree() {};
    FenwickTree(int NN) {
        N = NN;
        fenwick = vector<T>(N + 1, 0);
    }

    void update(int x, T val) {
        for (; x <= N; x += x & (-x)) fenwick[x] += val;
    }

    T sum(int x) {
        T res = 0;
        for (; x; x -= x & (-x)) res += fenwick[x];
        return res;
    }

    T get(int L, int R) {
        return sum(R) - sum(L - 1);
    }
};

struct event {
    int multiplier, c, d, idx;
    event() {};
    event(int _multiplier, int _c, int _d, int _idx) {
        multiplier = _multiplier;
        c = _c;
        d = _d;
        idx = _idx;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    vector<int> all_values;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        all_values.push_back(x[i]);
    }
    // a, b, c, d: f(a, c, d) = count x_i in range [c, d] for prefix x[1..a] -> query = f(b, c, d) - f(a - 1, c, d)
    vector<vector<int>> queries(q, vector<int>(4));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2] >> queries[i][3];
        queries[i][0]--;
        queries[i][1]--;
        all_values.push_back(queries[i][2]);
        all_values.push_back(queries[i][3]);
    }
    sort(all_values.begin(), all_values.end());
    all_values.resize(unique(all_values.begin(), all_values.end()) - all_values.begin());
    for (int &v : x) {
        v = lower_bound(all_values.begin(), all_values.end(), v) - all_values.begin() + 1;
    }
    for (int i = 0; i < q; i++) {
        queries[i][2] = lower_bound(all_values.begin(), all_values.end(), queries[i][2]) - all_values.begin() + 1;
        queries[i][3] = lower_bound(all_values.begin(), all_values.end(), queries[i][3]) - all_values.begin() + 1;
    }
    // build events
    vector<vector<event>> events(n);
    for (int i = 0; i < q; i++) {
        if (queries[i][0]) {
            events[queries[i][0] - 1].push_back(event(-1, queries[i][2], queries[i][3], i));
        }
        events[queries[i][1]].push_back(event(1, queries[i][2], queries[i][3], i));
    }
    vector<int> answer(q, 0);
    FenwickTree<int> fw(all_values.size());
    for (int i = 0; i < n; i++) {
        fw.update(x[i], 1);
        for (const auto& e : events[i]) {
            answer[e.idx] += fw.get(e.c, e.d) * e.multiplier;
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