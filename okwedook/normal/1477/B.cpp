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
    template<class T> void pdbg(const T &x) { print(x); }
    template<class T, class U> void pdbg(const pair<T, U> &p) {
        print('{');
        pdbg(p.f);
        print(',');
        pdbg(p.s);
        print('}');
    }
    void pdbg(const string &s) { print("\"" + s + "\""); }
    template<class It> void pdbg(It begin, It end, string d);
    template<class T> void pdbg(const vector<T> &a) { pdbg(all(a), ""); }
    template<class T> void pdbg(const vector<vector<T>> &a) { pdbg(all(a), "\n"); }
    template<class T> void pdbg(const vector<vector<vector<T>>> &a) { pdbg(all(a), "\n\n"); }
    template<class T> void pdbg(const set<T> &a) { pdbg(all(a), ""); }
    template<class T> void pdbg(const hashset<T> &a) { pdbg(all(a), ""); }
    template<class T, class U> void pdbg(const map<T, U> &a) { pdbg(all(a), ""); }
    template<class T, class U> void pdbg(const hashmap<T, U> &a) { pdbg(all(a), ""); }
    template<class It> void pdbg(It begin, It end, string d) {
        print('{');
        if (begin != end) pdbg(*begin++);
        while (begin != end)
            print(",", d), pdbg(*begin++);
        print('}');
    }
    template<class T> void dbgout(const T &x) { pdbg(x); }
    template<class T, class... U>
    void dbgout(T const &t, const U &... u) {
        pdbg(t);
        print(", ");
        dbgout(u...);
    }
    #define dbg(...) print("[", #__VA_ARGS__, "] = "), dbgout(__VA_ARGS__), flushln()
#else
    #define dbg(...) 0
#endif

template<class T, class U> inline bool chmin(T &x, const U& y) { return y < x ? x = y, 1 : 0; }
template<class T, class U> inline bool chmax(T &x, const U& y) { return y > x ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

struct node {
    int len = 1;
    char p = '2';
    int c0 = 0, c1 = 0;
    node() {}
    void upd(char x) {
        p = x;
        if (x == '0') c0 = len, c1 = 0;
        else c1 = len, c0 = 0;
    }
    void upd(const node &t) {
        upd(t.p);
    }
    bool updated() const {
        return p != '2';
    }
    void unupdate() {
        p = '2';
    }
};

node merge(const node &a, const node &b) {
    node ans;
    ans.len = a.len + b.len;
    ans.c1 = a.c1 + b.c1;
    ans.c0 = a.c0 + b.c0;
    return ans;
}

template<class node, node (*merge)(const node&, const node&) = merge>
struct Tree {
    int n = 1;
    vector<node> t;
    node& operator[](int ind) { return t[ind + n]; }
    const node& operator[](int ind) const { return t[ind + n]; }
    void submerge(int v) { // merge v's sons to v
        if (v >= n) return;
        t[v] = merge(t[v + v], t[v + v + 1]);
    }
    void resize(int sz) { // allocation
        while (n < sz) n <<= 1;
        t.resize(2 * n + 1);
    }
    void blank() { // default values
        for (int i = 0; i < 2 * n; ++i)
            t[i] = node();
    }
    void build() {
        for (int i = n - 1; i > 0; --i)
            submerge(i);
    }
    template<class T>
    void assign(const vector<T> &a) { // copy of a
        resize(sz(a));
        for (int i = 0; i < sz(a); ++i)
            t[i + n] = a[i];
        for (int i = sz(a); i < n; ++i)
            t[i + n] = node();
        build();
    }
    Tree() {} // empty
    Tree(int sz) { resize(sz); blank(); } // size, default values
    template<class T> Tree(const vector<T> &a) { assign(a); } // copy of a
    template<class T>
    void updup(int i, const T &val) { // upd at i with val, doesn't support push
        i += n;
        t[i].upd(val);
        for (i >>= 1; i > 0; i >>= 1)
            submerge(i);
    }
    node getup(int l, int r) { // get at [l, r), doesn't support push
        l += n;
        r += n;
        int cr = r;
        node left, right;
        bool lf = true, rf = true;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) left = lf ? lf = false, t[l++] : merge(left, t[l++]);
            if (r & 1) right = rf ? rf = false, t[--r] : merge(t[--r], right);
        }
        if (lf) return right;
        if (rf) return left;
        return merge(left, right);
    }
    void push(int v) {
        if (t[v].updated()) {
            t[v + v].upd(t[v]);
            t[v + v + 1].upd(t[v]);
            t[v].unupdate();
        }
    }
    // update [l, r) with value x, supports push
    template<class T>
    void upd(int l, int r, const T &x, int v, int vl, int vr) {
        if (vl >= r || vr <= l) return;
        if (vl >= l && vr <= r) return t[v].upd(x);
        push(v);
        int vm = vl + vr >> 1;
        upd(l, r, x, v + v, vl, vm);
        upd(l, r, x, v + v + 1, vm, vr);
        submerge(v);
    }
    template<class T>
    void upd(int l, int r, const T &x) { upd(l, r, x, 1, 0, n); }

    // get at [l, r), supports push
    node get(int l, int r, int v, int vl, int vr) {
        if (vl >= r || vr <= l) return node();
        if (vl >= l && vr <= r) return t[v];
        push(v);
        int vm = vl + vr >> 1;
        if (r <= vm) return get(l, r, v + v, vl, vm);
        if (l >= vm) return get(l, r, v + v + 1, vm, vr);
        return merge(get(l, r, v + v, vl, vm), get(l, r, v + v + 1, vm, vr));
    }
    node get(int l, int r) { return get(l, r, 1, 0, n); }

    void megapush(int v = 1) {
        if (v >= n) return;
        push(v);
        megapush(2 * v);
        megapush(2 * v + 1);
    }
};

void solve() {
    int n, q;
    read(n, q);
    string s, f;
    read(s, f);
    vector<pii> p(q);
    read(p);
    for (auto &i : p) --i.f, --i.s;
    reverse(p);
    Tree<node> t(n);
    for (int i = 0; i < n; ++i) {
        t[i].len = 1;
        t[i].upd(f[i]);
    }
    t.build();
    for (auto i : p) {
        int l = i.f, r = i.s;
        auto query = t.get(l, r + 1);
        dbg(query.c0, query.c1);
        int mx = (r - l) / 2;
        if (query.c0 <= mx) {
            t.upd(l, r + 1, '1');
        } else if (query.c1 <= mx) {
            t.upd(l, r + 1, '0');
        } else {
            println("NO");
            return;
        }
    }
    for (int i = 0; i < n; ++i)
        if ((s[i] == '0') != t.get(i, i + 1).c0) {
            dbg(t.get(i, i + 1).c1);
            println("NO");
            return;
        }
    println("YES");
}

signed main() {
    FAST; FIXED;
    int t;
    read(t);
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}