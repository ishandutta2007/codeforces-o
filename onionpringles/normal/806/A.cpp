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


ll gcd(ll a, ll b) {
	if (!b)return a;
	else return gcd(b, a%b);
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
#endif
	int T; ni(T);
	while (T--) {
		int x, y, p, q;
		nii(x, y); nii(p, q);
		if (p == q) {
			if (x < y) {
				puts("-1");
			}
			else puts("0");
			continue;
		}

		if (p == 0) {
			if(x) puts("-1");
			else puts("0");
			continue;
		}
		ll g = gcd(p, q);
		ll A = -x;
		ll B = x - y;
		ll dA = p / g;
		ll dB = (q - p) / g;
		ll lb = (x + dA - 1) / dA;
		lb = max(lb, (y - x + dB - 1) / dB);
		A += dA*lb;
		B += dB*lb;
		printf("%lld\n", A + B);
	}

	return 0;
}