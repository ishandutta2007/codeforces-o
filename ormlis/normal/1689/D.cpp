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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 5e6 + 30;
const int LG = 100;

void solve() {
    int n, m;
    cin >> n >> m;
    ar<int, 4> res = {-INFi, -INFi, -INFi, -INFi};
    rep(i, n) {
        rep(j, m) {
            char x;
            cin >> x;
            if (x == 'B') {
                rep(mask, 4) {
                    int cur = 0;
                    if (mask & 1) cur += i;
                    else cur -= i;
                    if (mask & 2) cur += j;
                    else cur -= j;
                    res[mask] = max(res[mask], cur);
                }
            }
        }
    }
    ar<int, 3> ans = {INFi, 0, 0};
    rep(i, n) rep(j, m) {
        int val = 0;
        rep(mask, 4) {
            int cur = 0;
            if (mask & 1) cur -= i;
            else cur += i;
            if (mask & 2) cur -= j;
            else cur += j;
            val = max(val, cur + res[mask]);
        }
        ans = min(ans, {val, i, j});
    }
    cout << ans[1] + 1 << ' ' << ans[2] + 1 << '\n';
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