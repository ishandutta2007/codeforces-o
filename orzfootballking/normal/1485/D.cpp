/*

DP





ll int
 dp 










*/
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
int a[505][505],T=720720;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>a[i][j];
		}
	}
	FOR(i,1,n){
		FOR(j,1,m){
			if((i+j)&1){
				a[i][j]=T+a[i][j]*a[i][j]*a[i][j]*a[i][j];
			}else a[i][j]=T;
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
	RE 0;
}