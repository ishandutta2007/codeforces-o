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
const int maxN = 1e5;

void solve() {
    string s;
    cin >> s;
    auto check = [&]() {
        int bal = 0;
        bool ok = true;
        for (auto x : s) {
            if (x == '(') bal++;
            else bal--;
            ok &= (bal >= 0);
        }
        ok &= (bal == 0);
        return ok;
    };
    vi pos;
    int bal = 0;
    rep(i, s.size()) {
        if (s[i] == '?') pos.push_back(i);
        else if (s[i] == '(') bal++;
        else bal--;
    }
    bal *= -1;
    int x = 0;
    int y = pos.size();
    while(x - y < bal && y > 0) {
        x++;
        y--;
    }
    if (x - y != bal) {
        cout << "NO\n";
        return;
    }
    rep(i, pos.size()) {
        if (i < x) s[pos[i]] = '(';
        else s[pos[i]] = ')';
    }
    if (!check()) {
        cout << "NO\n";
        return;
    }
    if (x != 0 && y != 0) {
        swap(s[pos[x - 1]], s[pos[x]]);
        if (check()) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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