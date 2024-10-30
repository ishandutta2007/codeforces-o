#pragma GCC optimize("O3","unroll-loops")

#include <bits/stdc++.h>
using namespace std;

#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(NULL))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

template<class T1, class T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<class T1, class T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<class T1> inline void sort(T1 &arr) { sort(all(arr)); }
template<class T1> inline void rsort(T1 &arr) { sort(rall(arr)); }
template<class T1> inline void reverse(T1 &arr) { reverse(all(arr)); }
template<class T1> inline void shuffle(T1 &arr) { 
    for (int i = -int(arr.size()); i < int(arr.size()); ++i)
        swap(arr[rand() % arr.size()], arr[rand() % arr.size()]);
}
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;
ll n;

ll sign(ll a) {
    if (a < 0) return -1;
    if (a == 0) return 0;
    return 1;
}

ll ask(ll i) {
    cout << "? " << i << endl;
    ll ans;
    cin >> ans;
    return ans;
}

ll question(ll i) {
    ll a = ask(i);
    ll b = ask(i + n / 2);
    return b - a;
}

signed main() {
    FAST; FIXED; RANDOM;
    cin >> n;
    ll from = sign(question(1));
    ll l = 0, r = n / 2 + 1;
    while (r - l > 1) {
        ll m = r + l >> 1;
        ll ans = question(m);
        if (ans == 0) {
            cout << "! " << m;
            return 0;
        }
        if (sign(ans) == from) l = m;
        else r = m;
    }
    cout << "! -1";
    return 0;
}