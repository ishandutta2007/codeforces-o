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
using namespace std;
int n,a[100005],b[100005],cnt[100005];
set<int> start;
set<P<int,int>,greater<P<int,int> > > s;
void solve(){
	cin>>n;
	start.clear();s.clear();
	FOR(i,1,n)cin>>a[i],b[a[i]]=i,start.insert(i),cnt[i]=1,s.insert(MP(1,i));
	int maxi,t;
	FOR(i,1,n){
		t=b[i];maxi=(*s.begin()).F;
		auto iter=start.lwb(t);
		if(cnt[t]!=maxi||iter==start.end()||(*iter)!=t){
			cout<<"No\n";RE;
		}
		auto now=iter;
		iter++;
		if(iter!=start.end()){
			s.erase(MP(cnt[(*iter)],(*iter)));
			cnt[(*iter)]+=cnt[(*now)];
			s.insert(MP(cnt[(*iter)],(*iter)));
		}
		s.erase(MP(cnt[(*now)],(*now)));
		start.erase(now);
	}
	cout<<"Yes\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}