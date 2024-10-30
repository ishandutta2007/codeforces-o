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

	cin >> N >> M;
	int a = 0, b = 0, c = 0;
	for (int i = 1; i <= 6; i++) {
		if (abs(i - N) < abs(i - M))a++;
		else if (abs(i - N) == abs(i - M))b++;
		else c++;
	}
	cout << a << " " << b << " " << c << endl;
	return 0;
}