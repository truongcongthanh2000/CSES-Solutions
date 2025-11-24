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

const int maxN = 1e4 + 10;

struct Trie_String{
    vector <vector<int> > T;
    vector <bool> End;
    int numNode;
    int cap, Base;
    Trie_String(){};
    Trie_String(int maxN, int _Base) {
        cap = maxN;
        Base = _Base;
        numNode = 0;
        T = vector<vector<int> > (cap, vector<int>(Base, 0));
        End = vector<bool> (cap, false); ///End[u] = true if we has a complete string in Node u
    }

    void add(string s) {
        int root = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a'; ///change if s not contain only alphabet
            assert(c >= 0 && c < Base);
            if (T[root][c] == 0) T[root][c] = ++numNode;
            root = T[root][c];
            assert(root < cap);
        }
        End[root] = true;
    }

    bool find(string s) { ///if we have a complete string t = s then return true, else return false
        int root = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a'; ///change if s not contain only alphabet
            assert(c >= 0 && c < Base);
            if (T[root][c] == 0) return false;
            root = T[root][c];
        }
        return End[root];
    }

    bool findPrefix(string s) { ///if we have a complete string t so s is the prefix in t then return true, else return false
        int root = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - '0';
            if (T[root][c] == 0) return false;
            root = T[root][c];
        }
        return true;
    }

    ///add method
};

int dp[maxN];
void sol() {
    string s;
    cin >> s;
    int n = (int)s.size();
    int k;
    cin >> k;
    Trie_String Tr(1000010, 26);
    while (k--) {
        string s;
        cin >> s;
        Tr.add(s);
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        int root = 0;
        int j = i;
        while (j <= n && Tr.T[root][s[j - 1] - 'a']) {
            root = Tr.T[root][s[j - 1] - 'a'];
            if (Tr.End[root]) {
                dp[j] = (dp[j] + dp[i - 1]) % MOD;
            }
            j++;
        }
    }
    cout << dp[n];
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
