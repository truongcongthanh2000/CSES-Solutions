#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

const int maxN = 3e6 + 100;

int power(int a, int n) {
    int ans = 1;
    for (; n; n >>= 1, a = 1LL * a * a % MOD) {
        if (n & 1) {
            ans = 1LL * ans * a % MOD;
        }
    }
    return ans;
}

int inverse(int a) {
    return power(a, MOD - 2);
}

// https://www.geeksforgeeks.org/dsa/orbit-counting-theorem-or-burnsides-lemma/
void solve() {
    int n;
    cin >> n;
    int f0 = power(2, 1LL * n * n % (MOD - 1));
    int f180 = power(2, (1LL * n * n + 1) / 2 % (MOD - 1));
    int f90 = power(2, (1LL * n * n + 3) / 4 % (MOD - 1));
    int ans = f0;
    ans = (ans + f180) % MOD;
    ans = (ans + f90) % MOD;
    ans = (ans + f90) % MOD;
    cout << 1LL * ans * inverse(4) % MOD << '\n';
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