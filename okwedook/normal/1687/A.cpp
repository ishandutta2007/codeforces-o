#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
}

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using graph = vector<vector<int>>;

const ld eps = 1e-9;
const int mod = 1000000007;
const ll inf = 3000000000000000007ll;

#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
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
    namespace TypeTraits {
        template<class T> constexpr bool IsString = false;
        template<> constexpr bool IsString<string> = true;
        template<class T, class = void> struct IsIterableStruct : false_type{};
        template<class T>
        struct IsIterableStruct<
            T,
            void_t<
                decltype(begin(declval<T>())),
                decltype(end(declval<T>()))
            >
        > : true_type{};
        template<class T> constexpr bool IsIterable = IsIterableStruct<T>::value;
        template<class T> constexpr bool NonStringIterable = !IsString<T> && IsIterable<T>;
        template<class T> constexpr bool DoubleIterable = IsIterable<decltype(*begin(declval<T>()))>;
    };
    template<class T>
    auto pdbg(const T &x) -> enable_if_t<!TypeTraits::NonStringIterable<T>, string> {
        stringstream ss;
        ss << x;
        return ss.str();
    }
    template<class T, class U>
    string pdbg(const pair<T, U> &x) {
        return "{" + pdbg(x.f) + "," + pdbg(x.s) + "}";
    }
    string pdbg(const string &x) {
        return "\"" + x + "\"";
    }
    template<class T>
    auto pdbg(const T &x) -> enable_if_t<TypeTraits::NonStringIterable<T>, string> {
        auto begin = x.begin();
        auto end = x.end();
        string del = "";
        if (TypeTraits::DoubleIterable<T>) {
            del = "\n";
        }
        string ans;
        ans += "{" + del;
        if (begin != end) ans += pdbg(*begin++);
        while (begin != end) {
            ans += "," + del + pdbg(*begin++);
        }
        ans += del + "}";
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

void makePref(vector<ll> &p) {
    for (int i = 1; i < sz(p); ++i) {
        p[i] += p[i - 1];
    }
}

ll getPref(const vector<ll> &p, int l, int r) {
    if (l > r) return 0;
    return p[r] - (l > 0 ? p[l - 1] : 0);
}

ll getSum(ll from, ll to, ll d) {
    if (from > to) return 0;
    // assert(from <= to);
    assert((to - from) % d == 0);
    return (to + from) * ((to - from) / d + 1) / 2;
}

ll processAdd(ll n, ll start, ll k) {
    // dbg(n, start, k);
    bool flag = n == 5 && k == 6 && start == 2;
    // dbg(flag);
    ll ans = 0;
    {
        ll d = min(start, k);
        ans += getSum(0, d, 1);
        k -= d;
    }
    if (k == 0) return ans;
    {
        ll d = min(start, k);
        ans += getSum(2, 2 * d, 2);
        if (flag) {
            dbg(ans, d);
        }
        k -= d;
    }
    if (k == 0) return ans;
    {
        ll d = min(n - 1 - start, k);
        ans += getSum(2 * start + 1, 2 * start + d, 1);
        // dbg(ans, 2 * start + 1, 2 * start + d);
        k -= d;
    }
    if (k == 0) return ans;
    {
        ll cnt = n - 1;
        ll sum = getSum(2, 2 * (n - 1), 2);
        ll x = (k / cnt);
        ans += sum * x;
        k -= cnt * x;
    }
    if (k == 0) return ans;
    {
        ans += getSum(2, 2 * k, 2);
        k = 0;
    }
    return ans;
}

ll processA(const vector<ll> &p, ll start, ll k) {
    ll d = min(k, start);
    bool flag = true;
    if (flag) {
        dbg(k);
        dbg(start - d, start);
    }
    ll ans = getPref(p, start - d, start);
    if (d == k) {
        return ans;
    }
    ll l = start + 1;
    ll r = min(ll(sz(p) - 1), k - start);
    if (flag) {
        dbg(l, r);
    }
    ans += getPref(p, l, r);
    if (flag) {
        dbg(ans);
    }
    return ans;
}

ll backSolve(vector<ll> a, ll k) {
    int n = sz(a);
    auto pref = a;
    makePref(pref);
    ll ans = 0;
    for (ll start = 0; start < n; ++start) {
        ll s = start;
        ll check = 0;
        check += processAdd(n, start, k);
        check += processA(pref, start, k);
        chmax(ans, check);
    }
    return ans;
}

void solve() {
    int n;
    ll k;
    read(n, k);
    vector<ll> a(n);
    read(a);
    if (n == 1) {
        msg("N = 1");
        println(a[0] + (k - 1));
        return;
    }
    --k;
    auto ans = backSolve(a, k);
    reverse(a);
    chmax(ans, backSolve(a, k));
    println(ans);
}

signed main() {
    initIO();
    int t;
    read(t);
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}