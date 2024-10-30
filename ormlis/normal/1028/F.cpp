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
const int maxN = 1e5 + 100;
const int LG = 20;


const int md = 1e9 + 7;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}

void solve() {
    map<pair<int, int>, int> cnt;
    int q;
    cin >> q;
    map<ll, set<pair<int, int>>> pts;
    int cur = 0;
    auto chng = [&](int x, int y, int c) {
        int g = __gcd(x, y);
        cnt[{x / g, y / g}] += c;
    };
    rep(_, q) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            ll r = 1ll * x * x + 1ll * y * y;
            for (auto &[x2, y2] : pts[r]) {
                int x3 = x2 + x;
                int y3 = y2 + y;
                chng(x3, y3, 2);
            }
            pts[r].insert({x, y});
            chng(x, y, 1);
            cur++;
        } else if (t == 2) {
            ll r = 1ll * x * x + 1ll * y * y;
            pts[r].erase({x, y});
            for (auto &[x2, y2] : pts[r]) {
                int x3 = x2 + x;
                int y3 = y2 + y;
                chng(x3, y3, - 2);
            }
            chng(x, y, -1);
            cur--;
        } else {
            int g = __gcd(x, y);
            x /= g;
            y /= g;
            cout << cur - cnt[{x, y}] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}