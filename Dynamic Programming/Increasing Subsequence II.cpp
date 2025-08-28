#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
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
        for (; x <= N; x += x & (-x)) fenwick[x] = (fenwick[x] + val) % MOD;
    }

    T sum(int x) {
        T res = 0;
        for (; x; x -= x & (-x)) res = (res + fenwick[x]) % MOD;
        return res;
    }

    T get(int L, int R) {
        return (sum(R) - sum(L - 1) + MOD) % MOD;
    }
};

void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    int sz = 0;
    for (auto &it : m) {
        it.second = ++sz;
    }
    for (int &v : a) {
        v = m[v];
    }
    FenwickTree<int> fw(sz);
    int ans = 0;
    for (int v : a) {
        int subseq = 1 + fw.sum(v - 1);
        ans = (ans + subseq) % MOD;
        fw.update(v, subseq);
    }
    cout << ans << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}