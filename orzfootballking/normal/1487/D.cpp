/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
V<int> v;
void solve(){
	int x;
	cin>>x;
	int it=upb(ALL(v),x)-v.begin();
	cout<<it<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=3;i*i<=2e9;i+=2){
		v.PB(1+(i*i-1)/2);
	}
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}