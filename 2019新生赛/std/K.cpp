#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,c[100005],cnt[100005],mx,son[100005],siz[100005],hson;
ll ans[100005],sum;
vector<int> e[100005];

void dfs1(int now,int fa)
{
    son[now]=0,siz[now]=1;
    for(auto to:e[now])
    {
        if(to==fa) continue;
        dfs1(to,now);
        siz[now]+=siz[to];
        if(siz[to]>siz[son[now]]) son[now]=to;
    }
}

void cal(int now,int fa,int y)
{
    cnt[c[now]]+=y;
    if(cnt[c[now]]==mx) sum+=c[now];
    else if(cnt[c[now]]>mx) mx=cnt[c[now]],sum=c[now];
    for(auto to:e[now])
        if(to!=fa&&to!=hson) cal(to,now,y);
}

void dfs2(int now,int fa,int keep)
{
    for(auto to:e[now])
    {
        if(to==fa||to==son[now]) continue;
        dfs2(to,now,0);
    }
    if(son[now]) dfs2(son[now],now,1);
    hson=son[now];
    cal(now,fa,1);hson=0;
    ans[now]=sum;
    if(!keep) cal(now,fa,-1),sum=0,mx=0;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",c+i);
    for(int i=1,x,y;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        e[x].push_back(y),e[y].push_back(x);
    }
    dfs1(1,1);
    dfs2(1,1,1);
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
    return 0;
}
