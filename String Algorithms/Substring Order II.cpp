#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int maxN = 3e5 + 100;

long long dp[maxN], cnt[maxN];
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
        cnt[cur] = 1;
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
                cnt[C] = 0;
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

long long dfs_dp(int root, const SuffixAutomation &sam) {
    if (dp[root] > 0) {
        return dp[root];
    }
    for (int c = 0; c < 26; c++) {
        if (sam.states[root].next[c] != -1) {
            dp[root] += dfs_dp(sam.states[root].next[c], sam);
        }
    }
    return dp[root] += cnt[root];
}

void dfs(int root, long long &k, string &ans, const SuffixAutomation &sam) {
    if (k < cnt[root]) {
        return;
    }
    k -= cnt[root];
    for (int c = 0; c < 26; c++) {
        int v = sam.states[root].next[c];
        if (v != -1) {
            if (k >= dp[v]) {
                k -= dp[v];
            } else {
                ans += char(c + 'a');
                return dfs(v, k, ans, sam);
            }
        }
    }
}

void solve() {
    string s;
    cin >> s;
    long long k;
    cin >> k;
    SuffixAutomation sam(s);

    vector<pair<int, int>> v(sam.states.size());
    for (int i = 0; i < v.size(); i++) {
        v[i] = {sam.states[i].len, i};
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    for (auto [len, id] : v) {
        if (sam.states[id].link != -1) {
            cnt[sam.states[id].link] += cnt[id];
        }
    }
    cnt[0] = 1;
    dfs_dp(0, sam);
    string ans;
    dfs(0, k, ans, sam);
    cout << ans << '\n';
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