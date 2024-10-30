//#define DEBUG
//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef long double ld;
const ll inf=1000000000000000001ll;
const ll mod=1000000007;
using namespace std;
mt19937 rnd(time(NULL));
const int N=400010;
int a[N];
int t[N*4];
void build(int v,int l,int r){
    if (l==r){
        t[v]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(v+v,l,m);
    build(v+v+1,m+1,r);
    t[v]=__gcd(t[v+v],t[v+v+1]);
}
int get(int v,int l,int r,int L,int R){
    if (l>R || r<L) return 0;
    if (l>=L && r<=R) return t[v];
    int m=(l+r)/2;
    return __gcd(get(v+v,l,m,L,R),get(v+v+1,m+1,r,L,R));
}
void solve(){
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    reverse(a+1,a+n+1);
    for (int i=1;i<=n;i++) a[i+n]=a[i];
    build(1,1,n+n);
    int res=0;
    int j=1;
    for (int i=n+1;i<=n*2;i++){
        while (j+1<=i && get(1,1,n+n,j+1,i)==t[1]) j++;
        res=max(res,i-j);
    }
    cout<<res<<endl;


}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;cin>>tt;
    while (tt--){
        solve();
    }
    return 0;
}
//ab+bc+ac