#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const int maxN = 3e5 + 10;
const int maxM = 20;
const int maxP = 1e4 + 10;
const long long INF_LL = 1e17;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 30;
const long double EPS = 1e-9;
const int BLOCK = 1000;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()); //comment this in SCPC
mt19937_64 rnd_64(chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

int a[maxN];
void sol() {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    map<int, bool> hasSum;
    for (int i = 2; i <= n; i++) {
        if (i >= 3) {
            for (int j = i + 1; j <= n; j++) {
                if (a[i] + a[j] <= x) {
                    int y = x - a[i] - a[j];
                    if (hasSum[y]) {
                        for (int u = 1; u < i - 1; u++) {
                            for (int v = u + 1; v < i; v++) {
                                if (a[u] + a[v] + a[i] + a[j] == x) {
                                    cout << u << " " << v << " " << i << " " << j;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int j = 1; j < i; j++) {
            int value = a[i] + a[j];
            if (value <= x) hasSum[value] = true;
        }
    }
    cout << "IMPOSSIBLE";
}
void solve() {
    int T;
    //cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        //cout << "Case #" << TestCase << ":" << ' ';
        sol();
    }
}

int main(int argc,char *argv[]) {
    ///srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}
