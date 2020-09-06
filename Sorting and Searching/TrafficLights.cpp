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

typedef pair<int, int> i2;
void sol() { ///median
    int x, n;
    cin >> x >> n;
    set<i2> lights;
    multiset<int> length;
    {
        lights.insert({x, 0});
        length.insert(x);
    }
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        auto it = lights.lower_bound({p, 0});
        int L = it->second;
        int R = it->first;
        lights.erase(it);
        length.erase(length.find(R - L)); ///don't use length.erase(R - L);
        {
            lights.insert({p, L});
            length.insert(p - L);
        }
        {
            if (L != R) {
                lights.insert({R, p});
                length.insert(R - p);
            }
        }
        cout << *length.rbegin() << ' ';
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

