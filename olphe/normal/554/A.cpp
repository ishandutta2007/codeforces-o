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
	set<string>st;
	for (int i = 0; i <= s.size(); i++) {
		for (char j = 'a'; j <= 'z'; j++) {
			string t;
			for (int k = 0; k < i; k++)t.push_back(s[k]);
			t.push_back(j);
			for (int k = i; k < s.size(); k++)t.push_back(s[k]);
			st.insert(t);
		}
	}
	cout << st.size() << endl;
	return 0;
}