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
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXN 1011
bool vis[MAXN];ll a[MAXN];
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)std::cin>>a[i];
    std::sort(a+1,a+n+1);
    ll ans=0;
    for(ll i=1;i<=n;++i)
        if(!vis[i])
        {
            for(ll j=i;j<=n;++j)
                if(a[j]%a[i]==0)vis[j]=1;
            ++ans;
        }
    std::cout<<ans;
}