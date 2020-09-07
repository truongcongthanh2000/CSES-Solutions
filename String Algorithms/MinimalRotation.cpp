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

int min_rotation(string s) {
    int a = 0, N = (int)s.size();
    for (int b = 0; b < N; b++) {
        for (int i = 0; i < N; i++) {
            if (a + i == b || s[(a + i) % N] < s[(b + i) % N]) {
                b += max(0, i - 1);
                break;
            }
            if (s[(a + i) % N] > s[(b + i) % N]) {
                a = b;
                break;
            }
        }
    }
    return a;
};

void sol() {
    string s;
    cin >> s;
    int n = (int)s.size();
    int a = min_rotation(s);
    for (int i = 0; i < n; i++) cout << s[(a + i) % n];
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
