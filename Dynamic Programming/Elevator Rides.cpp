#include <bits/stdc++.h>
 
using namespace std;
#define TASK "solve"
 
void doc() {
    #ifdef THEMIS
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    #endif // THEMIS
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
const int maxN = 3e5 + 100;
 
typedef pair<int, int> i2;
i2 dp[1 << 20];
int a[20];
void sol() {
    clock_t begin = clock();
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); mask++) {
        i2 &cost = dp[mask];
        cost = {n + 1, 0};
        for (int i = 0; i < n; i++) {
            int bit = (mask >> i) & 1;
            if (bit) {
                int pre_mask = mask ^ (1 << i);
                i2 old_dp = dp[pre_mask];
                if (old_dp.second + a[i] <= x) old_dp.second += a[i];
                else {
                    old_dp.first++;
                    old_dp.second = a[i];
                }
                cost = min(cost, old_dp);
            }
        }
    }
    cout << dp[(1 << n) - 1].first;
}
 
void solve() {
    int T;
    T = 1;
    //cin >> T;
    while (T--) sol();
}
 
int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    doc();
    solve();
}