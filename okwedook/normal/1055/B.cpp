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
ll n, m, l;

set<pll> st;
int ans = 0;

int getans(pll a) {
    return (a.s - a.f + 1 + l - 1) / l;
}

void add(int x) {
    auto it = st.lower_bound({x, x});
    pll a = {mod, mod}, b = {-5, -5};
    if (it != st.end()) a = *(it);
    if (it != st.begin()) b = *(--it);
    if (a.f == x + 1 && b.s == x - 1) {
        st.erase(a);
        st.erase(b);
        ans -= getans(a);
        ans -= getans(b);
        st.insert({b.f, a.s});
        ans += getans({b.f, a.s});
    } else if (a.f == x + 1) {
        st.erase(a);
        ans -= getans(a);
        st.insert({x, a.s});
        ans += getans({x, a.s});
    } else if (b.s == x - 1) {
        st.erase(b);
        ans -= getans(b);
        st.insert({b.f, x});
        ans += getans({b.f, x});
    } else {
        st.insert({x, x});
        ans += getans({x, x});
    }
}

signed main() {
    FAST; FIXED; RANDOM;
    cin >> n >> m >> l;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] > l) add(i);
    }
    while (m--) {
        int mode;
        cin >> mode;
        if (mode == 0) {
            cout << sz(st) << '\n';
        } else {
            int a, b;
            cin >> a >> b;
            --a;
            bool flag = arr[a] <= l;
            arr[a] += b;
            if (flag && arr[a] > l) add(a);
        }
    }
    return 0;
}