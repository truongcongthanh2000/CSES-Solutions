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

multiset<int> bigger, weak;
long long sum_bigger = 0, sum_weak = 0;

void fix() {
    while ((int)bigger.size() > (int)weak.size()) {
        auto it = bigger.begin();
        weak.insert(*it);
        sum_weak += *it;
        sum_bigger -= *it;
        bigger.erase(it);
    }
    while ((int)bigger.size() + 1 < (int)weak.size()) {
        auto it = weak.end();
        it--;
        bigger.insert(*it);
        sum_bigger += *it;
        sum_weak -= *it;
        weak.erase(it);
    }
    while ((int)bigger.size() && (int)weak.size() && *weak.rbegin() > *bigger.begin()) {
        auto it = weak.end(); it--;
        int x = *it;
        int y = *bigger.begin();
        weak.erase(it);
        bigger.erase(bigger.begin());
        weak.insert(y);
        bigger.insert(x);
        sum_bigger += x - y;
        sum_weak += y - x;
    }
}

void add(int x) {
    weak.insert(x);
    sum_weak += x;
    fix();
}

void remove(int x) {
    if (weak.find(x) != weak.end()) {
        weak.erase(weak.find(x));
        sum_weak -= x;
    }
    else {
        bigger.erase(bigger.find(x));
        sum_bigger -= x;
    }
    fix();
}
int a[maxN];
void sol() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < k; i++) add(a[i]);
    for (int i = k; i <= n; i++) {
        add(a[i]);
        int median = *weak.rbegin();
        cout << 1LL * median * (int)weak.size() - sum_weak + sum_bigger - 1LL * median * (int)bigger.size() << ' ';
        remove(a[i - k + 1]);
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
        sol();
    }
}

int main(int argc,char *argv[]) {
    ///srand(time(nullptr));
    ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
    open_file();
    solve();
}
