#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
char s[100100];
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		int cnt[3]={0,0,0};
		rep(i,n)cnt[s[i]-'A']++;
		puts(cnt[0]+cnt[2]==cnt[1]?"YES":"NO");
	}
    return 0;
}