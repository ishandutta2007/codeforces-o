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
	
	string s;
	cin>>s;
	vector<string>t(10);
	for(auto &i:t)cin>>i;
	for(int i=0;i<s.size();i+=10){
		string u;
		for(int j=0;j<10;j++){
			u.push_back(s[i+j]);
		}
		for(int j=0;j<10;j++){
			if(u==t[j])cout<<j;
		}
	}
	cout<<endl;
}