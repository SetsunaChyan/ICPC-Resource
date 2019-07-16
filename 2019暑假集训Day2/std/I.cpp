#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,tot,rk[100005],fa[100005];
ll ans;
struct edge
{
    int x,y;
    ll val;
}e[100005];

int _find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=_find(fa[x]);
}

void _un(int x,int y)
{
    x=_find(x),y=_find(y);
    fa[x]=y;
    rk[y]+=rk[x];
}

bool cmp(edge a,edge b){return a.val<b.val;}

void solve()
{
    ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) rk[i]=1,fa[i]=i;
    for(int i=0;i<n-1;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        e[i].x=x,e[i].y=y,e[i].val=z;
    }
    sort(e,e+n-1,cmp);
    for(int i=0;i<n-1;i++)
    {
        int x=_find(e[i].x),y=_find(e[i].y);
        ans+=((ll)rk[x]*rk[y]-1)*(e[i].val+1);
        _un(x,y);
    }
    printf("%lld\n",ans);
}

int main()
{
    solve();
    return 0;
}
