#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define pii pair<int,int>
#define ULL unsigned long long

#define LL long long
using namespace std;
namespace IO{
	const int BS=(1<<20)+5; int Top=0;
	char Buffer[BS],OT[BS],*OS=OT,*HD,*TL,SS[20]; const char *fin=OT+BS-1;
	char Getchar(){if(HD==TL){TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);} return (HD==TL)?EOF:*HD++;}
	void flush(){fwrite(OT,1,OS-OT,stdout),OS=OT;}
	void Putchar(char c){*OS++ =c;if(OS==fin)flush();}
	void write(int x){
		if(!x){Putchar('0');return;} if(x<0) x=-x,Putchar('-');
		while(x) SS[++Top]=x%10,x/=10;
		while(Top) Putchar(SS[Top]+'0'),--Top;
	}
	int read(){
		int nm=0,fh=1; char cw=getchar();
		for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
		for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
		return nm*fh;
	}
} using namespace IO;
int n,sum,ans=1;
char ch[1000000];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),scanf("%s",ch+1);
	for(int i=1;i<=n;i++) sum+=((ch[i]=='(')?1:-1),ans&=(sum>=-1);
	ans&=(sum==0);
	puts(ans?"Yes":"No");
	return 0;
}