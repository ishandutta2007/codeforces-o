#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
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
const int maxN = 2e5 + 5;
const int LG = 20;

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vi k(n), h(n);
    rep(i, n) cin >> k[i];
    rep(i, n) cin >> h[i];
    for(int i = n - 1; i >= 1; --i) {
        h[i - 1] = max(h[i - 1], h[i] - (k[i] - k[i - 1]));
    }
    ll ans = 0;
    int cur = 0;
    int t = 0;
    rep(i, n) {
        if (k[i] - t >= h[i]) {
            ans += 1ll * h[i] * (h[i] + 1) / 2;
            cur = h[i];
            t = k[i];
            continue;
        }
        ans += 1ll * (k[i] - t) * (k[i] - t + 1) / 2;
        ans += 1ll * (k[i] - t) * cur;
        cur += k[i] - t;
        t = k[i];
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}