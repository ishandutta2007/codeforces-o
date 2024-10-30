#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <iterator>
#include <random>
#include <time.h>
#include <tuple>
#include <functional>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)
#define FE(i,n) for(int i = 0; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//
const int N = 100000;
ll a[N];
ll b[N];
ll c[N];
int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n; ni(n);
	F(i, n)scanf("%lld", a + i);
	F(i, n - 1)b[i] = abs(a[i] - a[i + 1]);
	ll x[2][2];
	x[0][0] = 0;
	x[0][1] = 0;
	x[1][0] = 0;
	x[1][1] = 0;
	ll ans = -infl;
	for (int i = n - 2; i >= 0; i--) {
		c[i] = b[i] - c[i + 1];
		int k = i & 1;
		ans = max(ans, c[i] + x[k ^ 1][1]);
		ans = max(ans, c[i] - x[k][0]);
		x[k][0] = min(x[k][0], c[i]);
		x[k][1] = max(x[k][1], c[i]);
	}
	printf("%lld\n", ans);
	return 0;
}