#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[150010];
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        rep(i,n)scanf("%d",&a[i]);
        int ans=0,mn=a[n];
        for(int i=n;i;i--)ans+=a[i]>mn,mn=min(mn,a[i]);
        printf("%d\n",ans);
    }
    return 0;
}