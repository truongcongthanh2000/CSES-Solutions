#include <bits/stdc++.h>
 
using namespace std;
#define TASK "solve"
 
void doc() {
    #ifdef THEMIS
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    #endif
}
 
vector<long long> numDigits;
void init() {
    numDigits.push_back(1);
    long long pw = 1;
    for (int i = 1; i <= 17; i++) {
        numDigits.push_back(pw * i * 9);
        pw *= 10;
    }
}
 
void sol() {
    init();
    auto pos = [&](long long n) {
        int nDigits = 1;
        long long pw = 1;
        long long tmp = n;
        while (tmp >= 10) {
            tmp /= 10;
            pw *= 10;
            nDigits++;
        }
        long long ans = 0;
        for (int i = 1; i < nDigits; i++) ans += numDigits[i];
        ans += (n - pw + 1) * nDigits;
        return ans;
    };
    int q;
    cin >> q;
    while (q--) {
        long long k;
        cin >> k;
        long long l = 1, r = 1e17;
        long long ans = 1;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (pos(mid) >= k) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        int suf = pos(ans) - k;
        while (suf--) ans /= 10;
        cout << ans % 10 << '\n';
    }
}
 
void solve() {
    int T;
    //cin >> T;
    T = 1;
    while (T--) sol();
}
int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    doc();
    solve();
}