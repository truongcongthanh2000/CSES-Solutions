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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count()); //comment this in SCPC
mt19937_64 rnd_64(chrono::steady_clock::now().time_since_epoch().count());

void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}


string DIRECT = "URDL";
const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int maxN = 3e5 + 100;
typedef pair<int, int> i2;
typedef pair<long long, int> i2LL;
typedef pair<long long, i2> i3;

int dist[10][10];

bool inSide(int x, int y) {
    return x >= 1 && x <= 8 && y >= 1 && y <= 8 && dist[x][y] == 0;
}

int deg(int x, int y) {
    int res = 0;
    for (int i = 0; i < 8; i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        if (inSide(u, v)) {
            res++;
        }
    }
    return res;
}
void DFS(int x, int y, int d) {
    dist[x][y] = d;
    if (d == 64) {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) cout << dist[i][j] << ' ';
            cout << '\n';
        }
        exit(0);
    }
    vector<i2> canChoose;
    for (int i = 0; i < 8; i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        if (inSide(u, v)) {
            canChoose.push_back({u, v});
        }
    }
    sort(canChoose.begin(), canChoose.end(), [&](i2 a, i2 b) {
        return deg(a.first, a.second) < deg(b.first, b.second);
    });
    for (i2 it : canChoose) {
        DFS(it.first, it.second, d + 1);
    }
    dist[x][y] = 0;
}
void sol() {
    int x, y;
    cin >> x >> y;
    DFS(y, x, 1);
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
