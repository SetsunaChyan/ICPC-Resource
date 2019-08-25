#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN=5e5+5;
int seg[MAXN<<3],n,k,N,x;
ll ans;

void build(int rt,int l,int r)
{
    seg[rt]=0;
    if(l==r) return;
    int m=l+r>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
}

void modify(int rt,int l,int r,int x)
{
    if(l==r)
    {
        seg[rt]++;
        return;
    }
    int m=l+r>>1;
    if(x<=m) modify(rt<<1,l,m,x);
    else modify(rt<<1|1,m+1,r,x);
    seg[rt]=seg[rt<<1]+seg[rt<<1|1];
}

int query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[rt];
    int m=l+r>>1,ret=0;
    if(L<=m) ret+=query(rt<<1,l,m,L,R);
    if(m<R) ret+=query(rt<<1|1,m+1,r,L,R);
    return ret;
}

void solve()
{
    scanf("%d%d",&n,&k);
    N=2*n,ans=0;
    build(1,1,N);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        modify(1,1,N,x+i);
        if(k-x+i<=N) ans+=query(1,1,N,max(1,k-x+i),N);
    }
    printf("%lld\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
