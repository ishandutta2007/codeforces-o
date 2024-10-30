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

const double eps = 1e-6;
const int maxn = 112345;

double a[maxn];
int b[maxn], n;
bool vis[maxn];

int main() {
  ll tot = 0;
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%lf", a + i);
    if (abs(a[i] - round(a[i])) < eps) vis[i] = true;
    if (vis[i]) tot += round(a[i]);
    else tot += ceil(a[i]);
  }
  assert(tot >= 0);
  FOR(i, 1, n) {
    if (vis[i]) b[i] = round(a[i]);
    else {
      if (tot == 0) b[i] = ceil(a[i]);
      else {
        b[i] = floor(a[i]);
        tot--;
      }
    }
  }
  FOR(i, 1, n) printf("%d\n", b[i]);
}