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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int p[maxN];

void sol() {
    int n, q;
    cin >> n >> q;
    oset<pair<int, int> > s;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        s.insert({p[i], i});
    }

    while (q--) {
        char t;
        cin >> t;
        if (t == '!') {
            int k, x;
            cin >> k >> x;
            s.erase({p[k], k});
            p[k] = x;
            s.insert({p[k], k});
        }
        else {
            int a, b;
            cin >> a >> b;
            ///s.order_of_key(x): count number of s less than x
            int R = s.order_of_key({b + 1, 0});
            int L = s.order_of_key({a, 0});
            cout << R - L << '\n';
        }
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
