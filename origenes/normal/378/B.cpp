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

const int maxn = 112345;

int n;
int a[maxn], b[maxn];

int main() {
  scanf("%d", &n);
  REP(i, n) scanf("%d%d", a + i, b + i);
  int i = 0, j = 0;
  while (i + j < n) {
    if (i == n) j++;
    else if (j == n) i++;
    else if (a[i] < b[j]) i++;
    else j++;
  }
  chkmax(i, n / 2);
  chkmax(j, n / 2);
  REP(ii, i) putchar('1');
  REP(ii, n - i) putchar('0');
  putchar('\n');
  REP(jj, j) putchar('1');
  REP(jj, n - j) putchar('0');
}