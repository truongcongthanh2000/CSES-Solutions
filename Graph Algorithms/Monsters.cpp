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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int maxN = 1e3 + 100;
typedef pair<int, int> i2;

int n, m;
string s[maxN];
int Used[maxN][maxN];
int dA[maxN][maxN];
int dM[maxN][maxN];
int Trace[maxN][maxN];

bool inSide(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void getPath(int u, int v) {
    if (s[u][v] == 'A') return;
    int old_h = (Trace[u][v] + 2) % 4;
    getPath(u + dx[old_h], v + dy[old_h]);
    cout << DIRECT[Trace[u][v]];
}

void BFS(vector<i2> points, int dist[maxN][maxN]) {
    queue<i2> Q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = INF;
            Used[i][j] = 0;
            Trace[i][j] = 0;
        }
    }
    for (i2 A : points) {
        Q.push(A);
        Used[A.first][A.second] = 1;
        dist[A.first][A.second] = 0;
    }
    while ((int)Q.size()) {
        i2 A = Q.front(); Q.pop();
        int x = A.first;
        int y = A.second;
        for (int h = 0; h < 4; h++) {
            int u = x + dx[h];
            int v = y + dy[h];
            if (inSide(u, v) && s[u][v] != '#' && Used[u][v] == 0) {
                Used[u][v] = 1;
                dist[u][v] = dist[x][y] + 1;
                Trace[u][v] = h;
                Q.push({u, v});
            }
        }
    }
}
void sol() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<i2> pointsM;
    int xA = 0, yA = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'M') pointsM.push_back({i, j});
            if (s[i][j] == 'A') {
                xA = i;
                yA = j;
            }
        }
    }
    BFS(pointsM, dM);
    BFS({{xA, yA}}, dA);
    for (int i = 0; i < n; i++) {
        if (dA[i][0] < dM[i][0]) {
            cout << "YES" << '\n';
            cout << dA[i][0] << '\n';
            getPath(i, 0);
            return;
        }
        if (dA[i][m - 1] < dM[i][m - 1]) {
            cout << "YES" << '\n';
            cout << dA[i][m - 1] << '\n';
            getPath(i, m - 1);
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        if (dA[0][i] < dM[0][i]) {
            cout << "YES" << '\n';
            cout << dA[0][i] << '\n';
            getPath(0, i);
            return;
        }
        if (dA[n - 1][i] < dM[n - 1][i]) {
            cout << "YES" << '\n';
            cout << dA[n - 1][i] << '\n';
            getPath(n - 1, i);
            return;
        }
    }
    cout << "NO" << '\n';
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
