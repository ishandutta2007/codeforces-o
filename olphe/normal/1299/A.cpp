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

	cin>>N;
	vector<int>v(N);
	for(auto &i:v)cin>>i;
	vector<int>num(30);
	for(auto i:v){
		for(int j=0;j<30;j++){
			num[j]+=(i>>j)&1;
		}
	}
	int ans=-1;
	int fst=-1;
	for(auto i:v){
		int box=0;
		for(int j=0;j<30;j++){
			if((i>>j)&1){
				if(num[j]==1){
					box+=1<<j;
				}
			}
		}
		if(ans<box){
			ans=box;
			fst=i;
		}
	}
	//cout<<ans<<endl;
	cout<<fst;
	for(auto i:v){
		if(i==fst){
			fst=-MOD;
			continue;
		}
		cout<<" ";
		cout<<i;
	}
	cout<<endl;
}