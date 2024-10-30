#pragma GCC optimize("O3", "unroll-loops")
 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <complex>
#include <random>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <sstream>
#include <functional>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void checkmin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (x < y) x = y; }

const int N = 1000000;

ll cnt[N + 5];

signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    vector<vector<int>> del(N + 1);
    for (int i = 1; i <= N; ++i)
        for (int j = i; j <= N; j += i)
            del[j].pb(i);
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    cnt[0] = 1;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<pii> toadd;
        for (auto j : del[arr[i]]) {
            toadd.pb({j, cnt[j - 1]});
            ans += cnt[j - 1];
            if (ans >= mod) ans -= mod;
        }
        for (auto j : toadd) {
            cnt[j.f] += j.s;
            if (cnt[j.f] >= mod) cnt[j.f] -= mod;
        }
    }
    cout << ans;
    return 0;
}