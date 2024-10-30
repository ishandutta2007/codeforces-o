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

const int maxn = 65;

int n;
int a[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  if (n > 60) {
    cout << 1;
    return 0;
  }
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n) a[i] = a[i] ^ a[i - 1];
  int ans = 65;
  FOR(i, 1, n) FOR(j, i, n) FOR(k, j + 1, n) {
    int v1 = a[j] ^ a[i - 1], v2 = a[k] ^ a[j];
    if (v1 > v2) chkmin(ans, j - i + k - j - 1);
  }
  if (ans == 65) ans = -1;
  cout << ans;
}