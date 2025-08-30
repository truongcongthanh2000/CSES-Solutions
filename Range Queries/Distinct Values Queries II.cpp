#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

class SegmentTree {
   private:
    vector<int> IT;
    int n;

    void update(int i, int L, int R, int u, int val) {
        if (L > u || R < u) return;
        if (L == R) {
            IT[i] = val;
            return;
        }
        int mid = (L + R) >> 1;
        update(i << 1, L, mid, u, val);
        update(i << 1 | 1, mid + 1, R, u, val);
        IT[i] = min(IT[i << 1], IT[i << 1 | 1]);
    }

    int get(int i, int L, int R, int u, int v) {
        if (L > v || R < u) return MOD;
        if (L >= u && R <= v) return IT[i];
        int mid = (L + R) >> 1;
        int left = get(i << 1, L, mid, u, v);
        int right = get(i << 1 | 1, mid + 1, R, u, v);
        return min(left, right);
    }

   public:
    SegmentTree(int _n = 1) {
        IT = vector<int>(_n * 4, 0);
        n = _n;
    }
    void update(int u, int val) {
        update(1, 0, n - 1, u, val);
    }

    int get(int L, int R) {
        return get(1, 0, n - 1, L, R);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> all_values;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        all_values.push_back(x[i]);
    }
    vector<vector<int>> queries(q, vector<int>(3));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
        if (queries[i][0] == 1) {
            all_values.push_back(queries[i][2]);
            queries[i][1]--;
        } else {
            queries[i][1]--;
            queries[i][2]--;
        }
    }
    sort(all_values.begin(), all_values.end());
    all_values.resize(unique(all_values.begin(), all_values.end()) - all_values.begin());
    int m = all_values.size();
    vector<set<int>> positions(m);
    for (int i = 0; i < n; i++) {
        x[i] = lower_bound(all_values.begin(), all_values.end(), x[i]) - all_values.begin();
        positions[x[i]].insert(i);
    }
    for (int i = 0; i < q; i++) {
        if (queries[i][0] == 1) {
            queries[i][2] = lower_bound(all_values.begin(), all_values.end(), queries[i][2]) - all_values.begin();
        }
    }
    auto find_r = [&](int i) {
        int v = x[i];
        auto it = positions[v].lower_bound(i + 1);
        if (it == positions[v].end()) {
            return n;
        }
        return *it;
    };
    auto find_l = [&](int i) {
        int v = x[i];
        auto it = positions[v].lower_bound(i);
        if (it == positions[v].begin()) {
            return -1;
        }
        return *prev(it);
    };
    SegmentTree st(n);
    for (int i = 0; i < n; i++) {
        st.update(i, find_r(i));
    }
    for (int i = 0; i < q; i++) {
        int t = queries[i][0];
        if (t == 1) {
            int k = queries[i][1], u = queries[i][2];
            if (x[k] == u) {
                continue;
            }
            int old_l = find_l(k);
            if (old_l != -1) {
                st.update(old_l, find_r(k));
            }
            positions[x[k]].erase(k);
            x[k] = u;
            positions[u].insert(k);
            int new_l = find_l(k);
            st.update(k, find_r(k));
            if (new_l != -1) {
                st.update(new_l, k);
            }
        } else {
            int a = queries[i][1], b = queries[i][2];
            int min_r = st.get(a, b);
            if (min_r > b) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
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