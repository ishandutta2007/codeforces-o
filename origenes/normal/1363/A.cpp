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

const int maxn = 1123;

int x, n;
int a[maxn];

void solve() {
  scanf("%d%d", &n, &x);
  FOR(i, 1, n) scanf("%d", a + i);
  int even = 0, odd = 0;
  FOR(i, 1, n) {
    if (a[i] & 1) odd++;
    else even++;
  }
  if (!odd) {
    puts("NO");
    return;
  }
  odd--, x--;
  while (x > 1 && odd > 1) x -= 2, odd -= 2;
  while (x && even) x--, even--;
  puts(x ? "NO" : "YES");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}