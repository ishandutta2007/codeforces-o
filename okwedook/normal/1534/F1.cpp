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

struct dsu {
    struct rnk {
        int val = 1;
        int get() const {
            return val;
        }
        void add(const rnk &r) {
            val += r.val;
        }
    };
    vector<int> p;
    vector<rnk> r;
    int comp = 0, edge = 0;
    dsu() {}
    bool empty() const {
        return p.empty();
    }
    dsu(int n) {
        p = vector<int>(n);
        r = vector<rnk>(n);
        for (int i = 0; i < n; ++i)
            p[i] = i;
        comp = n;
    }
    int getp(int v) { // returns head element in a set
        return v == p[v] ? v : p[v] = getp(p[v]);
    }
    bool check(int a, int b) { // a and b are in one component
        return getp(a) == getp(b);
    }
    bool unite(int a, int b) { // a and b are in diff components
        a = getp(a);
        b = getp(b);
        if (a == b) return false;
        ++edge;
        --comp;
        if (r[a].get() > r[b].get()) swap(a, b);
        p[a] = b;
        r[b].add(r[a]);
        return true;
    }
};

vector<int> order;
vector<bool> used;
graph Gr;

void dfsorder(int v) {
    if (used[v]) return;
    used[v] = true;
    for (auto i : Gr[v])
        dfsorder(i);
    order.pb(v);
}

signed main() {
    FAST; FIXED;
    int n, m;
    read(n, m);
    vector<string> s(n);
    read(s);
    vector<int> cnt(m);
    read(cnt);
    vector<set<int>> st(m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] == '#') {
                st[j].insert(i);
            }
    vector<vector<vector<pii>>> G(n, vector<vector<pii>>(m));
    auto getlb = [](const set<int> &st, int x) -> int {
        auto it = st.lower_bound(x);
        if (it == st.end()) return -mod;
        return *it;
    };
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] == '#') {
                vector<pii> p;
                if (j > 0) p.pb({getlb(st[j - 1], i + 1), j - 1});
                p.pb({getlb(st[j], i + 1), j});
                if (j + 1 < m) p.pb({getlb(st[j + 1], i), j + 1});
                for (auto p : p)
                    if (p.f >= 0 && p.f < n && p.s >= 0 && p.s < m) {
                        G[p.f][p.s].pb({i, j});
                    }
            }
    dsu d(n * m);
    auto getind = [&](int i, int j) {
        return i * m + j;
    };
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] == '#') {
            if (i + 1 < n) {
                if (s[i + 1][j] == '#') {
                    d.unite(getind(i, j), getind(i + 1, j));
                }
            }
            if (j + 1 < m) {
                if (s[i][j + 1] == '#') {
                    d.unite(getind(i, j), getind(i, j + 1));
                }
            }
        }
    Gr = graph(n * m);
    vector<int> in(n * m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '#')
                for (auto p : G[i][j]) {
                    dbg(i, j, p.f, p.s);
                    int v = d.getp(getind(i, j));
                    int u = d.getp(getind(p.f, p.s));
                    if (u != v) {
                        Gr[u].pb(v);
                    }
                }
        }
    used = vector<bool>(n * m);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dfsorder(getind(i, j));
    reverse(order);
    used = vector<bool>(n * m);
    int ans = 0;
    for (auto ind : order) {
        int i = ind / m;
        int j = ind % m;
        if (s[i][j] == '#' && !used[ind] && d.getp(ind) == ind) {
            ++ans;
            dfsorder(ind);
        }
    }
    println(ans);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}