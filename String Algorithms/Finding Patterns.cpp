#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
 
using namespace std;
 
#define INP "solve"
#define OUT "solve"
 
/* some template */
 
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& a) {
    for (const auto& v : a) out << v << ' ';
    out << endl;
    return out;
}
 
template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<vector<T>>& a) {
    out << (int)a.size() << '\n';
    for (const auto& v : a) {
        for (const auto& value : v) out << value << ' ';
        out << endl;
    }
    return out;
}
 
template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}
/* end template */
 
const long long INF_LL = 5e18;
const int INF = 1e9 + 100;
const long double EPS = 1e-6;
const int BLOCK = 550;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
 
void open_file() {
#ifdef THEMIS
    freopen(INP ".txt", "r", stdin);
    freopen(OUT ".out", "w", stdout);
#endif  // THEMIS
}
 
const int maxN = 3e6 + 100;
const int MOD = 1e9 + 7;
 
struct SuffixArray {
    const int L;
    string s;
    vector<vector<int>> P;
    vector<pair<pair<int, int>, int>> M;
    /// P[k][i] = P[k][j] neu xau bat dau tu i co do dai 2^k = xau bat dau tu j co do dai 2^k
    SuffixArray(const string& s) : L(s.length()), s(s), P(1, vector<int>(L, 0)), M(L) {
        for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
        if (L == 1) P[0][0] = 0;  /// very important :)))), otherwise it may cause an error when L = 1
 
        for (int skip = 1, level = 1; skip < L; skip *= 2, level++) {
            P.push_back(vector<int>(L, 0));
            for (int i = 0; i < L; i++)
                M[i] = make_pair(make_pair(P[level - 1][i], i + skip < L ? P[level - 1][i + skip] : -1000), i);
            sort(M.begin(), M.end());
            for (int i = 0; i < L; i++)
                P[level][M[i].second] = (i > 0 && M[i].first == M[i - 1].first) ? P[level][M[i - 1].second] : i;
        }
    }
    vector<int> GetSuffixArray() { return P.back(); }
    // returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
    int LongestCommonPrefix(int i, int j) {
        int len = 0;
        if (i == j) return L - i;
        for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--) {
            if (P[k][i] == P[k][j]) {
                i += 1 << k;
                j += 1 << k;
                len += 1 << k;
            }
        }
        return len;
    }
};
 
void sol() {
    string s;
    cin >> s;
 
    int n = (int)s.size();
    SuffixArray sa(s);
    vector<int> rank = sa.GetSuffixArray();
 
    vector<int> id_rank(n);
    for (int i = 0; i < n; i++) id_rank[rank[i]] = i;
 
    auto cmp = [&](int Ls, const string& t, int needExtra) {
        int n = (int)s.size() - Ls;
        int m = (int)t.size();
        for (int i = 0; i < min(n, m); i++) {
            if (s[Ls + i] != t[i]) {
                if (s[Ls + i] < t[i]) return -1;
                return 1;
            }
        }
        if (!needExtra) return 0;
 
        if (n != m) {
            if (n < m) return -1;
            return 1;
        }
        return 0;
    };
 
    auto get_left = [&](const string& pattern) {
        // min i valid s[id_rank(i)..] >= pattern
        int L = 0, R = n - 1, ans = n;
        while (L <= R) {
            int mid = (L + R) >> 1;
            if (cmp(id_rank[mid], pattern, 1) >= 0) {
                R = mid - 1;
                ans = mid;
            } else {
                L = mid + 1;
            }
        }
        return ans;
    };
 
    int q;
    cin >> q;
    while (q--) {
        string pattern;
        cin >> pattern;
        int L = get_left(pattern);
        if (L == n || cmp(id_rank[L], pattern, 0) != 0)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
}
 
void solve() {
    clock_t start, end;
    start = clock();
    int T = 1;
    // cin >> T;
    int TestCase = 0;
    while (T--) {
        TestCase += 1;
        cerr << "Processing test = " << TestCase << '\n';
        // cout << "Case #" << TestCase << ": ";
        sol();
    }
    end = clock();
    cerr << "Time = " << (double)(end - start) / (double)CLOCKS_PER_SEC << '\n';
}
 
int main(int argc, char* argv[]) {
    // srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    open_file();
    solve();
    return 0;
}