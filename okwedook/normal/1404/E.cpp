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

#ifdef DEBUG
    template<class T> T to_dbg(T x) { return x; }
    template<class T, class U> string to_dbg(pair<T, U> p) {
        stringstream ss;
        ss << '{' << p.f << ',' << p.s << '}';
        return ss.str();
    }
    string to_dbg(string s) { return "\"" + s + "\""; }
    template<class It> string to_dbg(It begin, It end, string d = "") {
        stringstream ss;
        ss << '{';
        if (begin != end) ss << to_dbg(*begin++);
        while (begin != end)
            ss << "," << d << to_dbg(*begin++);
        ss << '}';
        return ss.str();
    }
    template<class T> string to_dbg(vector<T> a) { return to_dbg(all(a)); }
    template<class T> string to_dbg(set<T> a) { return to_dbg(all(a)); }
    template<class T> string to_dbg(hashset<T> a) { return to_dbg(all(a)); }
    template<class T, class U> string to_dbg(map<T, U> a) { return to_dbg(all(a), "\n"); }
    template<class T, class U> string to_dbg(hashmap<T, U> a) { return to_dbg(all(a), "\n"); }
    template<class T> void dbgout(T x) { cout << to_dbg(x) << endl; }
    template<class T, class... U>
    void dbgout(T t, U... u) {
        cout << to_dbg(t) << ", ";
        dbgout(u...);
    }
    #define dbg(...) cout << "[" << #__VA_ARGS__ << "] = ", dbgout(__VA_ARGS__);
#else
    #define dbg(...) 0
#endif

template<class T, class U> inline bool chmax(T &x, U y) { return x < y ? x = y, 1 : 0; }
template<class T, class U> inline bool chmin(T &x, U y) { return x > y ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }
void read() {} void print() {} void println() { cout << '\n'; }
template<class T, class ...U> void read(T &x, U& ... u) { cin >> x; read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { cout << x; print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { cout << x; println(u...); }

template<class F> struct Dinic {
    struct Edge { 
        int v, rev;
        F flow;
        Edge() {}
        Edge(int _v, F _cap, F _flow, int _rev) : 
            v(_v), flow(_flow - _cap), rev(_rev) {}
        inline bool sat() const { return flow >= 0; }
        inline bool unsat() const { return flow < 0; }
        inline F left() const { return -flow; }
        inline void addFlow(F x) { flow += x; }
    };
    vector<vector<Edge>> G;
    vector<int> layer, ptr;
    int n, s, t;
    Dinic(int _n) : n(_n) {
        G.resize(n);
        layer.resize(n);
    }
    void addEdge(int u, int v, F c) {
        int pu = sz(G[u]), pv = sz(G[v]);
        G[u].pb({v, c, 0, pv});
        G[v].pb({u, 0, 0, pu});
    }
    bool buildBfsTree() {
        for (int i = 0; i < n; ++i)
            layer[i] = -1;
        queue<int> que({s});
        layer[s] = 0;
        while (sz(que)) {
            auto f = que.front();
            que.pop();
            if (f == t) break;
            for (auto i : G[f])
                if (layer[i.v] == -1 && i.unsat()) {
                    layer[i.v] = layer[f] + 1;
                    que.push(i.v);
                }
        }
        return layer[t] >= 0;
    }
    F sendFlow(int v, F f) {
        if (v == t) return f;
        for (; ptr[v] < sz(G[v]); ++ptr[v]) {
            Edge& e = G[v][ptr[v]];
            if (layer[e.v] != layer[v] + 1 || e.sat()) continue;
            auto d = sendFlow(e.v, min(f, e.left()));
            if (d > 0) {
                e.addFlow(d);
                G[e.v][e.rev].addFlow(-d);
                return d;
            }
        }
        return 0;
    }
    F findFlow(int _s, int _t) {
        s = _s, t = _t;
        F ans = 0;
        while (buildBfsTree()) {
            ptr.assign(n, 0);
            while (F df = sendFlow(s, numeric_limits<F>::max()))
                ans += df;
        }
        return ans;
    }
};

int n, m;

int get(int i, int j, int ni, int nj) {
    return (min(i, ni) * m + min(j, nj)) * 2 + (j != nj);
}

bool ok(int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

signed main() {
    FAST; FIXED;
    read(n, m);
    vector<string> in(n);
    read(in);
    int sz = 2 * n * m + 2;
    int s = sz - 2, t = sz - 1;
    Dinic<int> fl(sz);
    vector<pii> d = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
    int cnt = 0, vert = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (in[i][j] == '#') {
                ++cnt;
                for (auto d : d) {
                    int ni = i + d.f, nj = j + d.s;
                    if ((ni > i || nj > j) && ok(ni, nj) && in[ni][nj] == '#') {
                        int ind = get(i, j, ni, nj);
                        if (ind & 1) fl.addEdge(ind, t, 1);
                        else fl.addEdge(s, ind, 1);
                        ++vert;
                    }
                }
                for (int x = 0; x < 4; ++x) {
                    int y = x + 1 & 3;
                    int i1 = i + d[x].f, j1 = j + d[x].s, i2 = i + d[y].f, j2 = j + d[y].s;
                    if (ok(i1, j1) && ok(i2, j2) && in[i1][j1] == '#' && in[i2][j2] == '#') {
                        int ind1 = get(i, j, i1, j1), ind2 = get(i, j, i2, j2);
                        assert(ind1 % 2 + ind2 % 2 == 1);
                        if (ind1 & 1) swap(ind1, ind2);
                        fl.addEdge(ind1, ind2, 1);
                    }
                }
            }
    println(cnt - (vert - fl.findFlow(s, t)));
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}