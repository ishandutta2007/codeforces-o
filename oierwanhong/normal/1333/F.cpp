//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<28)
ll read()
{
	ll x=0,f=1;
	char c;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
#define MAXN 500011
bool vis[MAXN];
ll p[MAXN],f[MAXN];
int main()
{
    ll n=read(),cnt=0;
    for(ll i=2;i<=n;++i)
    {
        if(!vis[i])p[++cnt]=i,++f[1];
        for(ll j=1;j<=cnt&&i*p[j]<=n;++j)
        {
            ++f[i];
            vis[i*p[j]]=1;
            if(i%p[j]==0)break;
        }
    }
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=f[i];++j)printf("%lld ",i);
}