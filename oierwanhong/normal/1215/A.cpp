//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<58;
/**********/
int main()
{
    ll a=read(),b=read(),k1=read(),k2=read(),n=read();
    ll ans=0;
    if(k1<k2)ans=min(n,a*k1)/k1+max(n-a*k1,0)/k2;
    else ans=(min(n,b*k2)/k2)+max(n-b*k2,0)/k1;
    printf("%lld %lld",max(n-(k1-1)*a-(k2-1)*b,0),ans);
}