#pragma GCC optimize("O3", "unroll-loops")

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

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
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
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

graph G, tree;
vector<bool> used;

void orient(int v) {
    queue<int> que;
    que.push(v);
    used[v] = true;
    while (sz(que)) {
        auto fr = que.front();
        que.pop();
        for (auto i : G[fr])
            if (!used[i]) {
                tree[fr].pb(i);
                used[i] = true;
                que.push(i);
            }
    }
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    cin >> n >> m;
    G = tree = graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    used = vector<bool>(n);
    pii mx = {-1, -1};
    for (int i = 0; i < n; ++i)
        checkmax(mx, pii(sz(G[i]), i));
    orient(mx.s);
    for (int i = 0; i < n; ++i)
        for (auto j : tree[i]) cout << i + 1 << ' ' << j + 1 << '\n';
    return 0;
}