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

int t, p, f, b, h, c, ans;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d%d", &b, &p, &f, &h, &c);
    if (h > c) {
      ans = min(b / 2, p) * h;
      b -= 2 * p;
      ans += max(0, min(b / 2, f)) * c;
    } else {
      ans = min(b / 2, f) * c;
      b -= 2 * f;
      ans += max(0, min(b / 2, p)) * h;
    }
    printf("%d\n", ans);
  }
}