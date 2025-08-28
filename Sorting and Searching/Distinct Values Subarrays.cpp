#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    deque<int> d;
    set<int> s;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (s.count(x)) {
            s.erase(d.front());
            d.pop_front();
        }
        d.push_back(x);
        s.insert(x);
        ans += d.size();
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