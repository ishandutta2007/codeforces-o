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

const int maxn = 212345;

ll k;
int n, a[maxn];

void solve() {
  scanf("%d%lld", &n, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  int mx = *max_element(a + 1, a + n + 1);
  int mn = *min_element(a + 1, a + n + 1);
  FOR(i, 1, n) {
    if (k % 2 == 0) a[i] = a[i] - mn;
    else a[i] = mx - a[i];
  }
  FOR(i, 1, n) printf("%d ", a[i]);
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}