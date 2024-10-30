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

void solve() {
    int n;
    read(n);
    vector<int> a(n);
    read(a);
    if (n % 2 == 1) {
        println("NO");
        return;
    }
    int l = 0, r = n - 1;
    sort(a);
    set<int> st;
    set<int> can;
    vector<int> cnt(n);
    for (int i = 0; i < n; i += 2) {
        st.insert(i);
        cnt[i] = 2;
    }
    vector<int> ans(n, -1);
    // auto upd = [&](int id, int val) {
    //     ans[id] = val;
    //     int prev = (id + n - 1) % n;
    //     int nxt = (id + 1) % n;
    //     if ((++cnt[prev]) == 2) {
    //         can.insert(prev);
    //     }
    //     if ((++cnt[nxt]) == 2) {
    //         can.insert(nxt);
    //     }
    // };
    // for (int i = 0; i < n; ) {
    //     int j = i;
    //     for (; j < n && a[j] == a[i]; ++j) {
    //         if (sz(can)) {
    //             int id = *can.begin();
    //             upd(id, a[j]);
    //             can.erase(id);
    //         } else {
    //             break;
    //         }
    //     }
    //     for (; j < n && a[j] == a[i]; ++j) {
    //         if (sz(st)) {
    //             int id = *st.begin();
    //             upd(id, a[j]);
    //             st.erase(id);
    //         } else {
    //             break;
    //         }
    //     }
    //     for (; j < n && a[j] == a[i]; ++j) {
    //         dbg(ans);
    //         println("NO");
    //         return;
    //     }
    //     i = j;
    // }
    for (int i = 0; i < n; ++i) {
        ans[(2 * i) % n + (2 * i >= n)] = a[i];
    }
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        int prev = ans[(i + n - 1) % n];
        int nxt = ans[(i + 1) % n];
        if (!(ans[i] < prev && ans[i] < nxt || ans[i] > prev && ans[i] > nxt)) {
            flag = false;
        }
    }
    dbg(ans);
    if (flag) {
        println("YES");
        for (auto i : ans) print(i, ' ');
        println();
        return;
    } else {
        println("NO");
    }
    // println("YES");
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