#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int LG = 20;

void solve() {
    int n;
    cin >> n;
    vi h(n);
    rep(i, n) cin >> h[i];
    if (n % 2 == 1) {
        ll ans = 0;
        for (int i = 1; i < n; i += 2) {
            ans += max(0, max(h[i - 1], h[i + 1]) + 1 - h[i]);
        }
        cout << ans << '\n';
        return;
    }
    vl pref(n), suf(n);
    {
        ll cur = 0;
        for (int i = 1; i + 1 < n; i += 2) {
            cur += max(0, max(h[i - 1], h[i + 1]) + 1 - h[i]);
            pref[i] = cur;
        }
    }
    {
        ll cur = 0;
        for (int i = n - 2; i >= 1; i -= 2) {
            cur += max(0, max(h[i - 1], h[i + 1]) + 1 - h[i]);
            suf[i] = cur;
        }
    }
    ll ans = min(suf[2], pref[n - 3]);
    for(int i = 2; i + 2 < n; i += 2) {
        ans = min(ans, pref[i - 1] + suf[i + 2]);
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}