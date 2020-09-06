#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const int maxN = 2e4 + 10;
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

string s;
int res = 0;
bool Choose[10][10];
string direct = "URDL";
int steps = 0;
void GridPaths(int x, int y) {
    //cout << id << " " << x << " " << y << '\n';
    if (x == 6 && y == 0) {
        if (steps == 48) res++;
        return;
    }
    bool canNotMove = Choose[x][y];
    if (y > 0 && y < 6 && Choose[x][y - 1] == false && Choose[x][y + 1] == false &&
        ((x == 0 && Choose[x + 1][y] == true) || (x == 6 && Choose[x - 1][y] == true))) canNotMove = true;
    if (x > 0 && x < 6 && Choose[x - 1][y] == false && Choose[x + 1][y] == false &&
        ((y == 0 && Choose[x][y + 1] == true) || (y == 6 && Choose[x][y - 1] == true))) canNotMove = true;
    if (x > 0 && x < 6 && y > 0 && y < 6 && Choose[x - 1][y] == true &&
        Choose[x + 1][y] == true && Choose[x][y - 1] == false && Choose[x][y + 1] == false) canNotMove = true;
    if (x > 0 && x < 6 && y > 0 && y < 6 && Choose[x][y - 1] == true &&
        Choose[x][y + 1] == true && Choose[x - 1][y] == false && Choose[x + 1][y] == false) canNotMove = true;
    if (canNotMove) {
        return;
    }
    Choose[x][y] = true;
    if (s[steps] == '?') {
        for (int h = 0; h < 4; h++) {
            int next_x = x + dx[h];
            int next_y = y + dy[h];
            if (next_x >= 0 && next_x < 7 && next_y >= 0 && next_y < 7 && Choose[next_x][next_y] == false) {
                steps++;
                GridPaths(next_x, next_y);
                steps--;
            }
        }
    }
    else {
        int h = 0;
        if (s[steps] == 'R') h = 1;
        if (s[steps] == 'D') h = 2;
        if (s[steps] == 'L') h = 3;
        int next_x = x + dx[h];
        int next_y = y + dy[h];
        if (next_x >= 0 && next_x < 7 && next_y >= 0 && next_y < 7 && Choose[next_x][next_y] == false) {
            steps++;
            GridPaths(next_x, next_y);
            steps--;
        }
    }
    Choose[x][y] = false;
}
void sol() {
    cin >> s;
    GridPaths(0, 0);
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

