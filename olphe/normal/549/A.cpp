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
	
	cin>>H>>W;
	vector<string>s(H);
	for(auto &i:s)cin>>i;
	string face="face";
	sort(face.begin(),face.end());
	for(int i=1;i<H;i++){
		for(int j=1;j<W;j++){
			string t;
			t.push_back(s[i-1][j-1]);
			t.push_back(s[i-1][j]);
			t.push_back(s[i][j-1]);
			t.push_back(s[i][j]);
			sort(t.begin(),t.end());
			if(t==face)N++;
		}
	}
	cout<<N<<endl;
}