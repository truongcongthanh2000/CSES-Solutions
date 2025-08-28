#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <bits/stdc++.h>

using namespace std;

#define INP "solve"
#define OUT "solve"

const int maxN = 5e5 + 10;
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

struct customer {
    ///type = 1 -> arrival_time
    ///type = -1 -> leaving_time;
    int time, type;
    customer(){};
    customer(int _time, int _type) : time(_time), type(_type) {};
    bool operator < (const customer &A) {
        if (time != A.time) {
            return time < A.time;
        }
        return type > A.type;
    }
};

customer arr_customer[maxN];
void sol() {
    int n;
    cin >> n;
    int m = 0;
    for (int i = 0; i < n; i++) {
        int arrival_time, leaving_time;
        cin >> arrival_time >> leaving_time;
        arr_customer[m++] = customer(arrival_time, 1);
        arr_customer[m++] = customer(leaving_time, -1);
    }
    n = m;
    sort(arr_customer, arr_customer + n);
    int res = 0, s = 0;
    for (int i = 0; i < n; i++) {
        s += arr_customer[i].type;
        res = max(res, s);
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
