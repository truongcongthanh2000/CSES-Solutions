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

const int maxN = 1e6 + 10;

int p[123];
int dp[maxN];
void sol() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> p[i];
    sort(p + 1, p + 1 + k);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        bool win = false;
        for (int j = 1; j <= k; j++) {
            if (p[j] > i) break;
            if (dp[i - p[j]] == 0) {
                win = true;
                break;
            }
        }
        dp[i] = win;
        cout << (dp[i] == 1 ? 'W' : 'L');
    }
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
