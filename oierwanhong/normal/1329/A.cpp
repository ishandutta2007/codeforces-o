//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
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
#define MAXN 100011
ll a[MAXN],suf[MAXN],ans[MAXN];
int main()
{
    ll n=read(),m=read();
    for(ll i=1;i<=m;++i)a[i]=read();
    for(ll i=m;i;--i)suf[i]=suf[i+1]+a[i];
    if(suf[1]<n){puts("-1");return 0;}
    for(ll i=1;i<=m;++i)
    {
        if(a[i]>n-i+1){puts("-1");return 0;}
        ll pos=max(i,n-suf[i]+1);
        ans[i]=pos;
    }
    for(ll i=1;i<=m;++i)printf("%lld ",ans[i]);
    return 0;
}