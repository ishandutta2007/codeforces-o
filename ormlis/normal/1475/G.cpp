#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()


typedef long long ll;
typedef long double ld;
using namespace std;

// using namespace __gnu_pbds;

const ll INF = 1e18 + 5;
const int INFi = 2e9;
const int maxN = 2e5 + 1000;
const int md2 = 998244353;
const int md = 1e9 + 7;

int dp[maxN];
int cnt[maxN];

void solve() {
    int n;
    cin >> n;
    memset(cnt, 0, sizeof(cnt));
    memset(dp, 0, sizeof(dp));
    range(_, n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int ans = 0;
    for (int i = 1; i < maxN; ++i) {
        for (int j = i * 2; j < maxN; j += i) {
            dp[j] = max(dp[j], dp[i] + cnt[i]);
        }
        ans = max(ans, dp[i] + cnt[i]);
    }
    cout << n - ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}