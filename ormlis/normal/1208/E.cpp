#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int maxN = 2e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }

    int lower_bound(ll c) {
        int r = -1;
        for (int j = 19; j >= 0; --j) {
            int x = 1 << j;
            if (r + x < n && fenw[r + x] < c) {
                r += x;
                c -= fenw[r];
            }
        }
        return r + 1;
    }
};

void solve() {
    int n, w; cin >> n >> w;
    vector<ll> p(w + 1);
    range(_, n) {
        int l; cin >> l;
        vector<int> a(l);
        range(i, l) cin >> a[i];
        vector<int> bl(l, -1), br(l, l);
        vector<int> stk;
        range(i, l) {
            while(!stk.empty() && a[stk.back()] < a[i]) stk.pop_back();
            if (!stk.empty()) bl[i] = stk.back();
            stk.push_back(i);
        }
        stk.clear();
        for(int i = l - 1; i >= 0; --i) {
            while(!stk.empty() && a[stk.back()] <= a[i]) stk.pop_back();
            if (!stk.empty()) br[i] = stk.back();
            stk.push_back(i);
        }
        range(i, l) {
            int L = i;
            int R = L + (w - l);
            if (bl[i] != -1 || a[i] < 0) {
                L = max(L, (w - l) + bl[i] + 1);
            }
            if (br[i] != l || a[i] < 0) {
                R = min(R, br[i] - 1);
            }
            if (L <= R) {
                p[L] += a[i];
                p[R + 1] -= a[i];
            }
        }
    }
    for(int i = 1; i < w; ++i) p[i] += p[i - 1];
    range(i, w) cout << p[i] << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}