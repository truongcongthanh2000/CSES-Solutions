#pragma GCC diagnostic ignored "-Wunused-parameter"
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
 
using namespace std;
 
#define INP "solve"
#define OUT "solve"
 
const long long INF_LL = 1e17;
const int INF = 1e9 + 100;
const int MOD = 1e9 + 7;
const int Base = 311;
const long double EPS = 1e-10;
const int BLOCK = 1000;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
 
void open_file() {
    #ifdef THEMIS
        freopen(INP ".inp","r",stdin);
        freopen(OUT ".out","w",stdout);
    #endif // THEMIS
}
 
const int maxN = 5e5 + 100;
 
//https://www.geeksforgeeks.org/generate-n-bit-gray-codes/
vector<string> graycode(int n) {
    if (n == 0) {
        return {"0"};
    }
    vector<string> gray = {"0", "1"}; //graycode for n = 1
    for (int _n = 1; _n < n; _n++) {
        for (int i = (1 << _n) - 1; i >= 0; i--) {
            gray.push_back(gray[i]);
        }
        for (int i = 0; i < (1 << _n); i++) {
            gray[i] = "0" + gray[i];
        }
        for (int i = (1 << _n); i < (int)gray.size(); i++) {
            gray[i] = "1" + gray[i];
        }
    }
    return gray;
}
 
void sol() {
    int n;
    cin >> n;
    vector<string> ans = graycode(n);
    for (string gray : ans) {
        cout << gray << '\n';
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
        //cout << "Test " << TestCase << ": ";
        sol();
    }
}
int main(int argc,char *argv[]) {
    ///srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}
