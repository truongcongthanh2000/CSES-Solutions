#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int find_mex(vector<int> &a) {
    set<int> s(a.begin(), a.end());
    int mex = 0;
    while (s.count(mex)) mex++;
    return mex;
}

const int LIM = 2000;
int grundy[LIM];
void compute_grundy() {
    grundy[0] = grundy[1] = grundy[2] = 0;
    for (int i = 3; i < LIM; i++) {
        vector<int> v;
        for (int j = 1; 2 * j < i; j++) {
            v.push_back(grundy[j] ^ grundy[i - j]);
        }
        grundy[i] = find_mex(v);
    }
}

void solve() {
    int n;
    cin >> n;
    if (n >= LIM || grundy[n])  {
        cout << "first" << '\n';
    } else {
        cout << "second" << '\n'; 
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    compute_grundy();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}