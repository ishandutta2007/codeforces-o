#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
int main()
{
	int T;
	for(scanf("%d",&T);T--;)
	{
		int a,b;scanf("%d%d",&a,&b);
		if(a==b){puts("0");continue;}
		a=abs(a-b);
		printf("%d\n",(a-1)/10+1);
	}
	return 0;
}