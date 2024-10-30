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
#include <random>
#include <cassert>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
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

graph G;
vector<int> h;
vector<bool> used;
set<pii> usededge;
vector<vector<int>> ans;

void add(int a, int b) {
    usededge.insert({a, b});
    usededge.insert({b, a});
}

bool count(int a, int b) {
    return usededge.count({a, b});
}

void dfs(int v, int p = -1) {
    h[v] = p == -1 ? 0 : h[p] + 1;
    used[v] = true;
    for (auto i : G[v])
        if (!used[i]) dfs(i, v);
    vector<int> e;
    for (auto i : G[v])
        if (i != p && h[i] > h[v] && !count(i, v))
            e.pb(i);
    if (p != -1 && !count(v, p)) e.pb(p);
    for (int i = 0; i + 1 < sz(e); i += 2) {
        ans.pb({e[i], v, e[i + 1]});
        add(e[i], v);
        add(v, e[i + 1]);
    }
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    cin >> n >> m;
    G = graph(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].pb(b);
        G[b].pb(a);
    }
    h = vector<int>(n);
    used = vector<bool>(n);
    for (int i = 0; i < n; ++i)
        if (!used[i]) dfs(i);
    cout << sz(ans) << '\n';
    for (auto i : ans) {
        for (auto j : i) cout << j + 1 << ' ';
        cout << '\n';
    }
    return 0;
}