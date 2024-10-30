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
  int n, k;
  cin >> n >> k;
  vector<int> a(n), r(1e5 + 1);
  REP(i, n) cin >> a[i];
  uni(a); n = size(a);
  REP(i, n) {
    chkmax(r[0], a[i] / k);
    int l = 1;
    while (l <= a[0]) {
      int q = a[i] / l;
      chkmax(r[l], a[i] / min(q, k));
      l = a[i] / q + 1;
    }
  }
  int ans = r[0];
  FOR(l, 1, a[0]) {
    chkmax(r[l], r[l - 1]);
    chkmin(ans, r[l] - l);
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}