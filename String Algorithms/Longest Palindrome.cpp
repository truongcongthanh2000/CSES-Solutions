#pragma GCC diagnostic ignored "-Wunused-parameter"

#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const long long INF_LL = 1e18 + 100;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 30;
const long double EPS = 1e-9;
const int BLOCK = 1000;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

const int maxN = 2e6 + 10;

struct Manacher {
    string s;
    int n;
    vector<int> d1, d2;
    Manacher(){};
    Manacher(string _s) {
        s = _s;
        n = (int)s.size();
        d1 = vector<int>(n, 0);
        d2 = vector<int>(n, 0);
    }

    void calc() {
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
            while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
                k++;
            }
            d2[i] = k--;
            if (i + k > r) {
                l = i - k - 1;
                r = i + k ;
            }
        }
    }

    int getLenPalindrome(int root) {
        return max(d1[root] * 2 - 1, d2[root] * 2);
    }
};

void sol() {
    string s;
    cin >> s;
    Manacher df(s);
    df.calc();
    int n = (int)s.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        int len = df.getLenPalindrome(i);
        res = max(res, len);
    }
    for (int i = 0; i < n; i++) {
        int len = df.getLenPalindrome(i);
        if (len == res) {
            if (df.d1[i] * 2 - 1 == res) {
                int j = i - df.d1[i] + 1;
                cout << s.substr(j, len);
            }
            else {
                int j = i - df.d2[i];
                cout << s.substr(j, len);
            }
            return;
        }
    }
    cout << res << '\n';
}
void solve() {
    int T;
    //cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ":" << ' ';
        ///cout << "Case #" << TestCase << '\n';
        sol();
    }
}
int main(int argc,char *argv[]) {
    //srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}
