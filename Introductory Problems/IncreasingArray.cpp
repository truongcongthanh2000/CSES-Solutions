#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const int maxN = 120;
const int maxM = 20;
const int maxP = 1e4 + 10;
const long long INF_LL = 1e15;
const int INF = 1e9 + 100;
const int MOD = 998244353;
const int Base = 30;
const long double EPS = 1e-9;
const int BLOCK = 1000;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}

void sol() {
    int n;
    cin >> n;
    long long res = 0;
    int old = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x >= old) old = x;
        else {
            int dist = old - x;
           // cerr << x << " " << old << " " << dist << '\n';
            res += dist;
        }
    }
    cout << res;
}

void solve() {
    int T;
    ///cin >> T;
    T = 1;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        ///cout << "Case #" << TestCase << ": ";
        sol();
    }
}

int main(int argc,char *argv[]) {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}
