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
#include <array>
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

#ifndef __GNUG__
int __builtin_popcount(int n) {
	int x = 0;
	while (n)n -= n & (-n), x++;
	return x;
}
#endif

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const ll infl = 9012345678901234567;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

int a[2][101010];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int n, Q; nii(n, Q);
	int cnt = 0;
	while (Q--) {
		int x, y; nii(x, y);
		x--; y--;
		if (a[x][y]) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (j >= 0 && j < n && a[x ^ 1][j])cnt--;
			}
		}
		else {
			for (int j = y - 1; j <= y + 1; j++) {
				if (j >= 0 && j < n && a[x ^ 1][j])cnt++;
			}
		}
		a[x][y] ^= 1;
		if (cnt)puts("NO");
		else puts("YES");
	}

	return 0;
}