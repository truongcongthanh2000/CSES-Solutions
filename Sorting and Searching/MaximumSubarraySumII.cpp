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

int x[maxN];
long long s[maxN];
void sol() {
    int n, a, b;
    cin >> n >> a >> b;
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        s[i] = s[i - 1] + x[i];
    }
    multiset<long long> canChoose;
    long long res = -1e18;
    for (int i = 1; i <= n; i++) {
        if (i >= a) {
            canChoose.insert(s[i - a]);
            res = max(res, s[i] - *canChoose.begin());
        }
        if (i >= b) canChoose.erase(canChoose.find(s[i - b])); ///don't use erase(s[i - b]);
    }
    cout << res;
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
