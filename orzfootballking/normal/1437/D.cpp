#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
int a[200005],d[200005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int ans=0;
	FOR(i,2,n){
		ans++;
		int r=i+1;
		d[i]=d[ans]+1;
		while(r<=n&&a[r]>a[r-1])d[r]=d[ans]+1,r++;
		i=r-1;
	}
	cout<<d[n]<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	RE 0;
}