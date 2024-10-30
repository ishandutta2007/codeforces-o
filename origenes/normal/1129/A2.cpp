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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 5123;

int n, m;
int cnt[maxn], rec[maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) rec[i] = n - 1;
  FOR(i, 1, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    cnt[a]++;
    chkmin(rec[a], (b + n - a) % n);
  }
  FOR(i, 1, n) {
    int ans = 0;
    FOR(j, 1, n) if (cnt[j])
        chkmax(ans, rec[j] + (cnt[j] - 1) * n + (j + n - i) % n);
    printf("%d ", ans);
  }
}