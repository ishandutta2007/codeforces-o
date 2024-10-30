#pragma GCC optimize("O3", "unroll-loops")
 
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
#define RANDOM srand(235345)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define eps 1e-9
#define mod 998244353
#define inf 3000000000000000007ll
#define f first
#define s second
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

void solve() {
    ll a, b, m;
    cin >> a >> b >> m;
    if (a == b) {
        cout << 1 << ' ' << a << '\n';
        return;
    }
    for (int l = 1; l < 50; ++l) {
        ll d = (1ll << (l - 1));
        ll sum = d * a + d;
        if (sum > b) {
            cout << -1 << '\n';
            return;
        }
        ll sumup = d * a + d * m;
        if (sumup >= b) {
            vector<ll> r(l);
            r[0] = max(1ll, d / 2);
            for (int i = 1; i < l; ++i) r[i] = max(1ll, r[i - 1] / 2);
            ll add = b - d * a;
            ll left = d;
            for (int i = 0; i < l; ++i) {
                left -= r[i];
                ll t = min(m, (add - left) / r[i]);
                add -= t * r[i];
                r[i] = t;
            }
            vector<ll> x(l + 1);
            x[0] = a;
            for (int i = 1; i <= l; ++i) {
                for (int j = 0; j < i; ++j)
                    x[i] += x[j];
                x[i] += r[i - 1];
            }
            cout << sz(x) << ' ';
            for (auto i : x) cout << i << ' ';
            cout << '\n';
            return;
        }
    }
}

signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}