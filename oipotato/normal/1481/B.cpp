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
    for(scanf("%d",&T);T--;)
    {
        int n,k,a[110];
        scanf("%d%d",&n,&k);
        rep(i,n)scanf("%d",&a[i]);
        int last;
        rep(i,k)
        {
            last=-1;
            rep(j,n-1)if(a[j]<a[j+1]){a[j]++;last=j;break;}
            if(last==-1)break;
        }
        printf("%d\n",last);
    }
    return 0;
}