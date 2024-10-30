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
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	string s;
	cin >> s;
	if (K <= N / 2) {
		while (K > 1) {
			cout << "LEFT" << endl;
			K--;
		}
		cout << "PRINT " << s[0] << endl;
		for (int i = 1; i < N; i++) {
			cout << "RIGHT" << endl;
			cout << "PRINT " << s[i] << endl;
		}
	}
	else {
		while (K < N) {
			cout << "RIGHT" << endl;
			K++;
		}
		reverse(s.begin(), s.end());
		cout << "PRINT " << s[0] << endl;
		for (int i = 1; i < N; i++) {
			cout << "LEFT" << endl;
			cout << "PRINT " << s[i] << endl;
		}
	}
}