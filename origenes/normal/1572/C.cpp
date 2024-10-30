#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  vector<vector<int>> G(n);
  REP(i, n) {
    cin >> a[i];
    a[i]--;
    G[a[i]].eb(i);
  }
  vector<vector<int>> f(n, vector<int>(n));
  FOR(len, 2, n) REP(i, n - len + 1) {
    int j = i + len - 1;
    auto it = lower_bound(all(G[a[i]]), i); ++it;
    f[i][j] = f[i + 1][j];
    for (;it != G[a[i]].end() && *it <= j; ++it) chkmax(f[i][j], f[i + 1][*it - 1] + f[*it][j] + 1);
  }
  cout << n - 1 - f[0][n - 1] << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}