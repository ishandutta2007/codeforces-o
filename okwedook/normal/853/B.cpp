#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

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
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

const int N = 1e6 + 100;

struct arr {
    vector<ll> a;
    ll sum;
    int cnt = 0;
    arr(int n) {
        a = vector<ll>(n, mod);
        a[0] = 0;
        sum = 0;
        for (auto i : a) sum += i, cnt += i == mod;
    }
    void upd(int i, ll x) {
        if (a[i] == mod) --cnt;
        sum -= a[i];
        checkmin(a[i], x);
        sum += a[i];
        if (a[i] == mod) ++cnt;
    }
};

signed main() {
    FAST; FIXED;
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> allin(N, inf), allout(N, inf);
    vector<vector<pll>> in(N), out(N);
    for (int i = 0; i < m; ++i) {
        int d, f, t, c;
        cin >> d >> f >> t >> c;
        if (t == 0) in[d].pb({f, c});
        else out[d].pb({t, c});
    }
    arr c(n + 1);
    for (int i = 0; i < N; ++i) {
        for (auto j : in[i])
            c.upd(j.f, j.s);
        if (c.cnt == 0) allin[i] = c.sum;
    }
    c = arr(n + 1);
    for (int i = N - 1; i >= 0; --i) {
        for (auto j : out[i])
            c.upd(j.f, j.s);
        if (c.cnt == 0) allout[i] = c.sum;
    }
    ll ans = inf;
    for (int i = 0; i + k + 1 < N; ++i)
        checkmin(ans, allin[i] + allout[i + k + 1]);
    cout << (ans == inf ? -1 : ans);
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}