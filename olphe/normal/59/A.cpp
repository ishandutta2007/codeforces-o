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

	string s;
	cin >> s;
	for (auto i : s)N += i >= 'a';
	if (N * 2 >= s.size()) {
		for (auto&i : s) {
			if (i <= 'Z')i -= 'A' - 'a';
		}
	}
	else {
		for (auto&i : s) {
			if (i >= 'a')i -= 'a' - 'A';
		}
	}
	cout << s << endl;
	return 0;
}