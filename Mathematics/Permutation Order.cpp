#include <bits/stdc++.h>

using namespace std;

vector<long long> fact{1};

void sol1(int n, long long k) {
    while (fact.size() <= n) fact.push_back(fact.back() * fact.size());
    set<int> remain;
    for (int i = 1; i <= n; i++) remain.insert(i);
    for (int i = 1; i <= n; i++) {
        auto it = remain.begin();
        while (k > fact[n - i]) {
            k -= fact[n - i];
            it++;
        }
        cout << *it << ' ';
        remain.erase(it);
    }
    cout << '\n';
}

void sol2(int n, vector<int> &p) {
    while (fact.size() <= n) fact.push_back(fact.back() * fact.size());
    long long k = 1;
    set<int> remain;
    for (int i = 1; i <= n; i++) remain.insert(i);
    for (int i = 1; i <= n; i++) {
        auto it = remain.begin();
        while (*it != p[i - 1]) {
            k += fact[n - i];
            it++;
        }
        remain.erase(it);
    }
    cout << k << '\n';
}

void solve() {
    int t;
    cin >> t;
    if (t == 1) {
        int n;
        long long k;
        cin >> n >> k;
        sol1(n, k);
    } else {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        sol2(n, p);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}