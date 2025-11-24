#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

struct SegTree {
    int n;
    vector<char> t;
    SegTree(int n) : n(n), t(4 * n, '`') {}  // '`' < 'a'

    void setval(int idx, char v, int vtx, int l, int r) {
        if (l == r) {
            t[vtx] = v;
            return;
        }
        int m = (l + r) / 2;
        if (idx <= m)
            setval(idx, v, vtx * 2, l, m);
        else
            setval(idx, v, vtx * 2 + 1, m + 1, r);
        t[vtx] = max(t[vtx * 2], t[vtx * 2 + 1]);
    }

    void setval(int idx, char v) {
        setval(idx, v, 1, 0, n - 1);
    }

    char getmax(int ql, int qr, int vtx, int l, int r) {
        if (ql > r || qr < l) return '`';
        if (ql <= l && r <= qr) return t[vtx];
        int m = (l + r) / 2;
        return max(getmax(ql, qr, vtx * 2, l, m),
                   getmax(ql, qr, vtx * 2 + 1, m + 1, r));
    }

    char getmax(int l, int r) {
        if (l > r) return '`';
        return getmax(l, r, 1, 0, n - 1);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> sa(n);
    for (int i = 0; i < n; i++) cin >> sa[i], sa[i]--;
    vector<int> inv(n);
    for (int i = 0; i < n; i++) inv[sa[i]] = i;

    SegTree st(n);
    string s(n, ' ');
    char c = 'a';

    for (int i = 0; i < n; i++) {
        bool need_increment = false;
        if (i && sa[i] == n - 1) need_increment = true;
        if (sa[i] < n - 1) {
            int l = inv[sa[i] + 1] + 1;
            if (l < n) {
                char mx = st.getmax(l, n - 1);
                if (mx == c) {
                    need_increment = true;
                }
            }
        }
        if (need_increment) c++;
        if (c > 'z') {
            cout << -1 << '\n';
            return;
        }
        s[sa[i]] = c;
        if (sa[i] < n - 1) {
            st.setval(inv[sa[i] + 1], c);
        }
    }
    cout << s << '\n';
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