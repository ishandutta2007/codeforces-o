#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
int main()
{
    int n;scanf("%d",&n);
    int mx=0;
    rep(i,n){int x;scanf("%d",&x);mx=max(mx,x);}
    printf("%d\n",mx);
    return 0;
}