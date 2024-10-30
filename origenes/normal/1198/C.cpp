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

const int maxn = 312345;

int T, n, m;
bool vis[maxn];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    fill(vis + 1, vis + 3 * n + 1, false);
    vector<int> match;
    FOR(i, 1, m) {
      int u, v;
      scanf("%d%d", &u, &v);
      if (!vis[u] && !vis[v]) {
        match.eb(i);
        vis[u] = vis[v] = true;
      }
    }
    if (match.size() >= n) {
      puts("Matching");
      REP(i, n) printf("%d ", match[i]);
    } else {
      puts("IndSet");
      int need = n;
      FOR(i, 1, 3 * n) if (!vis[i]) {
        printf("%d ", i);
        if (!--need) break;
      }
    }
    putchar('\n');
  }
}