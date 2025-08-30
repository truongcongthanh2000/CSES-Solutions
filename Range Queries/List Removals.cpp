#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const long long INF_LL = 1e17;
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

const int maxN = 5e5 + 100;

int IT[maxN * 4], sum[maxN * 4];

void update(int i, int L, int R, int u, int val, int s) {
    if (L > u || R < u) return;
    if (L == R) {
        IT[i] += val;
        sum[i] += s;
        return;
    }
    int mid = (L + R) >> 1;
    update(i << 1, L, mid, u, val, s);
    update(i << 1 | 1, mid + 1, R, u, val, s);
    IT[i] = max(IT[i << 1], IT[i << 1 | 1]);
    sum[i] = sum[i << 1] + sum[i << 1 | 1];
}

pair<int, int> findID(int i, int L, int R, int val) { ///find x so min(h[1 -> x]) >= val
    if (sum[i] < val) return {-1, -1}; ///failed
    if (L == R) return {L, IT[i]};
    int mid = (L + R) >> 1;
    if (sum[i << 1] < val) {
        return findID(i << 1 | 1, mid + 1, R, val - sum[i << 1]);
    }
    return findID(i << 1, L, mid, val);
}
void sol() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        update(1, 1, n, i, x, 1);
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        pair<int, int> id_value = findID(1, 1, n, x);
        cout << id_value.second << ' ';
        update(1, 1, n, id_value.first, id_value.second, -1);
    }
}
void solve() {
    int T;
    ///cin >> T;
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
