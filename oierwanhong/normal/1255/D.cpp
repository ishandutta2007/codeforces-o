//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
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
const ll INF=1<<28;
/**********/
#define MAXN 111
char turn(ll x)
{
    if(x<=26)return 'A'+x-1;
    x-=26;
    if(x<=26)return 'a'+x-1;
    x-=26;
    return '0'+x-1;
}
char a[MAXN][MAXN];
ll c[MAXN][MAXN];
int main()
{
    ll task=read();
    while(task--)
    {
        ll n=read(),m=read(),k=read(),cur=1,cnt=0;
        for(ll i=1;i<=n;++i)
        {
            scanf("%s",a[i]+1);
            for(ll j=1;j<=m;++j)cnt+=(a[i][j]=='R');
        }
        ll t=0;
        for(ll i=1;i<=n;++i)
            for(ll j=i&1?1:m;j!=(i&1?m+1:0);j+=(i&1?1:-1))
            {
                t+=(a[i][j]=='R');
                c[i][j]=cur;
                if((cur<=cnt%k&&t==cnt/k+1)||(cur>cnt%k&&t==cnt/k))t=0,++cur;
                umin(cur,k);
            }
        for(ll i=1;i<=n;++i)
        {
            for(ll j=1;j<=m;++j)putchar(turn(c[i][j]));
            puts("");
        }
    }
    return 0;
}