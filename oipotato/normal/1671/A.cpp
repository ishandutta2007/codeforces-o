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
        char s[210];scanf("%s",s+1);
        int n=strlen(s+1);s[0]=s[n+1]=0;
        bool flag=1;
        rep(i,n)if(s[i]!=s[i-1]&&s[i]!=s[i+1])flag=0;
        puts(flag?"YES":"NO");
    }
    return 0;
}