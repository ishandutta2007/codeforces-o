#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const long long  int MOD = 998244353;
//long long int N, M, K, H, W, L, R;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N + 1);
	v[1] = 1;
	L = 1;
	R = 1;
	while (R <= N) {
		v[R] = 1;
		R += L;
		L = R - L;
	}
	for (int i = 1; i <= N; i++) {
		if (v[i])cout << "O";
		else cout << "o";
	}
	cout << endl;
	return 0;
}