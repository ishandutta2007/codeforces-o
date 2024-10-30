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


bool check(pii a, pii b, pii c) {
    if (a.f > b.f) swap(a.f, b.f);
    if (a.s > b.s) swap(a.s, b.s);
    return a.f <= c.f && c.f <= b.f && a.s <= c.s && c.s <= b.s;
}

int check(const vector<pii> &pos, pii s, pii c) {
    int ans = 0;
    for (auto i : pos)
        ans += check(i, s, c);
    return ans;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    pii s;
    cin >> n >> s;
    vector<pii> a(n);
    cin >> a;
    vector<pii> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    pii ans = {s.f + 1, s.s + 1};
    for (auto i : d) {
        pii c = {i.f + s.f, i.s + s.s};
        if (check(a, s, ans) < check(a, s, c)) ans = c;
    }
    cout << check(a, s, ans) << '\n';
    cout << ans.f << ' ' << ans.s;
    return 0;
}