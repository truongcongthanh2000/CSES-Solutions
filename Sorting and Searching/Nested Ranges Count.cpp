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
 
const int maxN = 1e6 + 100;
 
struct point {
    int x, val, id;
    point(){};
    point(int _x, int _val, int _id) {
        x = _x;
        val = _val;
        id = _id;
    }
    bool operator < (const point &A) {
        if (x != A.x) return x < A.x;
        return val < A.val;
    }
};
 
int fen[maxN];
 
void update(int x, int val) {
    for (; x < maxN; x += x & (-x)) {
        fen[x] += val;
    }
}
 
int get(int x) {
    if (x <= 0) return 0;
    int ans = 0;
    for (; x; x -= x & (-x)) {
        ans += fen[x];
    }
    return ans;
}
 
int sum(int L, int R) {
    return get(R) - get(L - 1);
}
array<int, 2> a[maxN];
int ans[maxN];
void sol() {
    int n;
    cin >> n;
    vector<int> nen;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
        nen.push_back(a[i][0]);
        nen.push_back(a[i][1]);
    }
    sort(nen.begin(), nen.end());
    for (int i = 1; i <= n; i++) {
        a[i][0] = lower_bound(nen.begin(), nen.end(), a[i][0]) - nen.begin() + 1;
        a[i][1] = lower_bound(nen.begin(), nen.end(), a[i][1]) - nen.begin() + 1;
    }
    {
        vector<point> A;
        for (int i = 1; i <= n; i++) {
            A.push_back(point(a[i][0], 1, i));
            A.push_back(point(a[i][1], -1, i));
        }
        sort(A.begin(), A.end());
        for (int i = 0; i < n * 2; ) {
            int j = i;
            while (j < 2 * n && A[j].x == A[i].x) j++;
            for (int k = i; k < j; k++) {
                if (A[k].val < 0) {
                    int id = A[k].id;
                    update(a[id][0], 1);
                }
            }
            for (int k = i; k < j; k++) {
                if (A[k].val < 0) {
                    int id = A[k].id;
                    ans[id] = sum(a[id][0], a[id][1]) - 1;
                }
            }
            i = j;
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    memset(fen, 0, sizeof(fen));
    {
        vector<point> A;
        for (int i = 1; i <= n; i++) {
            A.push_back(point(a[i][0], 1, i));
            A.push_back(point(a[i][1], -1, i));
        }
        sort(A.begin(), A.end());
        int numNode = 0;
        for (int i = 0; i < n * 2; ) {
            int j = i;
            while (j < 2 * n && A[j].x == A[i].x) j++;
            for (int k = i; k < j; k++) {
                if (A[k].val < 0) {
                    int id = A[k].id;
                    ans[id] = sum(1, a[id][0]) - 1;
                }
            }
            for (int k = i; k < j; k++) {
                if (A[k].val < 0) {
                    int id = A[k].id;
                    update(a[id][0], -1);
                }
                else {
                    update(A[k].x, 1);
                }
            }
            i = j;
        }
        for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << '\n';
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