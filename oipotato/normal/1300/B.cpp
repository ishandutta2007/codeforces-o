#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int a[200010];  
int main()
{
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;scanf("%d",&n);
        rep(i,2*n)scanf("%d",&a[i]);
        sort(a+1,a+2*n+1);
        printf("%d\n",a[n+1]-a[n]);
    }
    return 0;
}