#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <complex>
#include <random>
#include <cassert>
#include <chrono>
#include <functional>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) signed((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

void flush() { cout << flush; }
void flushln() { cout << endl; }
void println() { cout << '\n'; }
template<class T> void print(const T &x) { cout << x; }
template<class T> void read(T &x) { cin >> x; }
template<class T, class ...U> void read(T &x, U& ... u) { read(x); read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { print(x); print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { print(x); println(u...); }

#ifdef DEBUG
    template<class T> string pdbg(const T &x) { stringstream ss; ss << x; return ss.str(); }
    template<class T, class U> string pdbg(const pair<T, U> &p) { return "{" + pdbg(p.f) + "," + pdbg(p.s) + "}"; }
    string pdbg(const string &s) { return "\"" + s + "\""; }
    template<class It> string pdbg(It begin, It end, string d);
    template<class T> string pdbg(const vector<T> &a) { return pdbg(all(a), ""); }
    template<class T> string pdbg(const vector<vector<T>> &a) { return pdbg(all(a), "\n"); }
    template<class T> string pdbg(const vector<vector<vector<T>>> &a) { return pdbg(all(a), "\n\n"); }
    template<class T> string pdbg(const set<T> &a) { return pdbg(all(a), ""); }
    template<class T> string pdbg(const hashset<T> &a) { return pdbg(all(a), ""); }
    template<class T, class U> string pdbg(const map<T, U> &a) { return pdbg(all(a), ""); }
    template<class T, class U> string pdbg(const hashmap<T, U> &a) { return pdbg(all(a), ""); }
    template<class It> string pdbg(It begin, It end, string d) {
        string ans;
        ans += "{";
        if (begin != end) ans += pdbg(*begin++);
        while (begin != end)
            ans += "," + d + pdbg(*begin++);
        ans += "}";
        return ans;
    }
    template<class T> string dbgout(const T &x) { return pdbg(x); }
    template<class T, class... U>
    string dbgout(T const &t, const U &... u) {
        string ans = pdbg(t);
        ans += ", ";
        ans += dbgout(u...);
        return ans;
    }
    #define dbg(...) print("[", #__VA_ARGS__, "] = ", dbgout(__VA_ARGS__)), flushln()
    #define msg(...) print("[", __VA_ARGS__, "]"), flushln()
#else
    #define dbg(...) 0
    #define msg(...) 0
#endif

template<class T, class U> inline bool chmin(T &x, const U& y) { return y < x ? x = y, 1 : 0; }
template<class T, class U> inline bool chmax(T &x, const U& y) { return y > x ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

map<pair<pii, pii>, int> st;

int grundy(const vector<string> &s, int i1, int i2, int j1, int j2) {
    auto it = st.find({{i1, i2}, {j1, j2}});
    if (it != st.end()) return it->s;
    hashset<int> moves;
    int n = sz(s);
    int m = n > 0 ? sz(s[0]) : 0;
    for (int i = i1; i <= i2; ++i)
        for (int j = j1; j <= j2; ++j) {
            if (s[i][j] == 'L') {
                int a = grundy(s, i1, i - 1, j1, j2);
                int b = grundy(s, i + 1, i2, j1, j2);
                moves.insert(a ^ b);
            }
            if (s[i][j] == 'R') {
                int a = grundy(s, i1, i2, j1, j - 1);
                int b = grundy(s, i1, i2, j + 1, j2);
                moves.insert(a ^ b);
            }
            if (s[i][j] == 'X') {
                int a = grundy(s, i1, i - 1, j1, j - 1);
                int b = grundy(s, i1, i - 1, j + 1, j2);
                int c = grundy(s, i + 1, i2, j1, j - 1);
                int d = grundy(s, i + 1, i2, j + 1, j2);
                moves.insert(a ^ b ^ c ^ d);
            }
        }
    int ans = 0;
    while (moves.count(ans)) ++ans;
    return st[{{i1, i2}, {j1, j2}}] = ans;
}

signed main() {
    FAST; FIXED;
    int n, m;
    read(n, m);
    vector<string> s(n);
    read(s);
    int sz = (n + m) / 2;
    vector<string> odd(sz, string(sz, '#'));
    auto even = odd;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            auto &md = ((i + j) & 1) ? odd : even;
            int nx = (i + j) / 2;
            int ny = (i - j + (m - 1)) / 2;
            md[nx][ny] = s[i][j];
        }
    int vodd = grundy(odd, 0, sz - 1, 0, sz - 1);
    st.clear();
    int veven = grundy(even, 0, sz - 1, 0, sz - 1);
    println((vodd ^ veven) == 0 ? "LOSE" : "WIN");
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}