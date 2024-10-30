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

int n, x;
int deg[maxn];

void solve() {
  scanf("%d%d", &n, &x);
  reset(deg, 0);
  REP(i, n - 1) {
    int u, v;
    scanf("%d%d", &u, &v);
    deg[u]++, deg[v]++;
  }
  if (deg[x] <= 1) puts("Ayush");
  else puts((n - 1) % 2 == 1 ? "Ayush" : "Ashish");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}