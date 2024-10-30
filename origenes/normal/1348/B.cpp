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

const int maxn = 112;

int n, k;

void solve() {
  scanf("%d%d", &n, &k);
  vector<int> a(n);
  for (auto &x : a) scanf("%d", &x);
  sort(all(a));
  uni(a);
  if (a.size() > k) {
    puts("-1");
    return;
  }
  while (a.size() < k) a.eb(1);
  printf("%d\n", n * k);
  REP(i, n) for (auto x : a) printf("%d ", x);
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}