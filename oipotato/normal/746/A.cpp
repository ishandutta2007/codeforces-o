#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int T;
    // for(scanf("%d",&T);T--;)
    {
        int a,b,c;scanf("%d%d%d",&a,&b,&c);
        printf("%d\n",7*min(a,min(b/2,c/4)));
    }
    return 0;
}