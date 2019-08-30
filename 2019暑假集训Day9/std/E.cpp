#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%lld",&a)
#define pr(a) printf("%d",a)
#define per(a,b,c) for(int a=b;a<c;++a)
#define perr(a,b,c) for(int a=b;a<=c;++a)
const int inf=0x3f3f3f3f;
const int mod=2;

int _,n;
ll m;
ll a[44];
ll b[44];
ll c[2000001];
ll d[2000001];
int cn=0,dn=0;
void dfs(int n,int p,ll now,ll a[],ll c[],int &ct){
    if(now>m)return;
    if(p==n) {c[ct++]=now;return;}
    dfs(n,p+1,now,a,c,ct);
    dfs(n,p+1,now+a[p],a,c,ct); 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int n1=n/2;
    int n2=n-n1;
    per(i,0,n1)cin>>a[i];
    per(i,0,n2)cin>>b[i];
    dfs(n1,0,0,a,c,cn),sort(c,c+cn);
    dfs(n2,0,0,b,d,dn),sort(d,d+dn);
    ll ans=0;
    per(i,0,cn){
        ans+=upper_bound(d,d+dn,m-c[i])-d;
    }
    cout<<ans<<endl;
    return 0;
}