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
int n=262143,m=131072;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>k;
	cout<<"3 3\n";
	cout<<n<<' '<<n<<' '<<k<<'\n';
	cout<<n<<' '<<m<<' '<<n<<'\n';
	cout<<k<<' '<<n<<' '<<k<<'\n';
	RE 0;
}