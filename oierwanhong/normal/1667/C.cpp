


#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 1011;
int vis[MAXN][MAXN];
int main()
{
	int n=read();
	int m=0;
	while(m+((m+1)>>1)<n)++m;
	printf("%d\n",m);
	if(m&1)
	{
	int t=(m+1)>>1;
	for(int i=1;i<=t;++i)printf("%d %d\n",i,t-i+1);
	for(int i=1;i<=(m>>1);++i)printf("%d %d\n",t+i,t+((m>>1)-i)+1);
	}
	else
	{
		int t=m>>1;
		for(int i=1;i<=t;++i)printf("%d %d\n",i,t-i+1);
		printf("%d %d\n",t+1,t+1);
		for(int i=1;i<=t-1;++i)printf("%d %d\n",t+1+i,t+1+((t-1)-i)+1);
	}
	return 0;
}