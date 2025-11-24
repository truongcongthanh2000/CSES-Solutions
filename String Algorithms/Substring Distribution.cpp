#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int maxN = 3e5 + 100;

struct SuffixAutomation {
    struct State {
        int len, link;
        int next[26];
        State(int _len = 0, int _link = -1) : len(_len), link(_link) {
            memset(next, -1, sizeof(next));
        }
    };

    vector<State> states;
    int last;

    SuffixAutomation() {}

    SuffixAutomation(const string& S) {
        init(S);
    }

    inline int state(int len = 0, int link = -1) {
        states.emplace_back(len, link);
        return states.size() - 1;
    }

    void init(const string& S) {
        states.reserve(2 * S.size());
        last = state();
        for (char c : S)
            extend(c);
    }

    void extend(char _c) {
        int c = _c - 'a';  // change for different alphabet
        int cur = state(states[last].len + 1), P = last;
        while (P != -1 && states[P].next[c] == -1) {
            states[P].next[c] = cur;
            P = states[P].link;
        }
        if (P == -1)
            states[cur].link = 0;
        else {
            int Q = states[P].next[c];
            if (states[P].len + 1 == states[Q].len)
                states[cur].link = Q;
            else {
                int C = state(states[P].len + 1, states[Q].link);
                copy(states[Q].next, states[Q].next + 26, states[C].next);
                while (P != -1 && states[P].next[c] == Q) {
                    states[P].next[c] = C;
                    P = states[P].link;
                }
                states[Q].link = states[cur].link = C;
            }
        }
        last = cur;
    }
};


void solve() {
    string s;
    cin >> s;
    SuffixAutomation sam(s);

    vector<int> d(sam.states.size(), -1);
    queue<int> Q;
    d[0] = 0;
    Q.push(0);
    while (Q.size()) {
        int u = Q.front(); Q.pop();
        for (int c = 0; c < 26; c++) {
            int v = sam.states[u].next[c];
            if (v != -1 && d[v] == -1) {
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
    }
    vector<int> ans(s.size() + 2, 0);
    for (int i = 1; i < d.size(); i++) {
        ans[d[i]]++;
        ans[sam.states[i].len + 1]--;
    }
    for (int i = 1; i <= s.size(); i++) {
        ans[i] += ans[i - 1];
        cout << ans[i] << ' ';
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