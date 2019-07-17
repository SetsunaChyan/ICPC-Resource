#include <bits/stdc++.h>
using namespace std;

int par[10005],id[10005],n,m,q,fa[10005][20],va[10005][20],dep[10005],lg[10005],head[10005],tot=0,vis[10005];
struct edge
{
    int x,y,val;
}en[50005];
struct edge1
{
    int to,nxt,val;
}e[50005<<1];

bool cmp(edge a,edge b){return a.val>b.val;}
int _find(int x){return x==par[x]?x:par[x]=_find(par[x]);}
void _union(int x,int y){par[_find(x)]=_find(y);}

void add_edge(int x,int y,int z)
{
    e[tot].val=z;
    e[tot].to=y;
    e[tot].nxt=head[x];
    head[x]=tot++;
}

void dfs(int now,int f)
{
    vis[now]=1;
    dep[now]=dep[f]+1;
    fa[now][0]=f;
    for(int i=1;(1<<i)<=dep[now];i++)
        fa[now][i]=fa[fa[now][i-1]][i-1],va[now][i]=min(va[now][i-1],va[fa[now][i-1]][i-1]);
    for(int i=head[now];~i;i=e[i].nxt)
        if(!vis[e[i].to]) va[e[i].to][0]=e[i].val,dfs(e[i].to,now);
}

int solve(int x,int y)
{
    int ret=0x3f3f3f3f;
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y])
        ret=min(ret,va[x][lg[dep[x]-dep[y]]-1]),x=fa[x][lg[dep[x]-dep[y]]-1];
    if(x==y) return ret;
    for(int i=lg[dep[x]]-1;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
        {
            ret=min(ret,va[x][i]);
            ret=min(ret,va[y][i]);
            x=fa[x][i],y=fa[y][i];
        }
    ret=min(ret,va[x][0]);
    ret=min(ret,va[y][0]);
    return ret;
}

int main()
{
    memset(vis,0,sizeof(vis));
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i),par[i]=i;
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&en[i].x,&en[i].y,&en[i].val);
    sort(en,en+m,cmp);
    for(int i=0;i<m;i++)
        if(_find(en[i].x)!=_find(en[i].y))
        {
            _union(en[i].x,en[i].y);
            add_edge(en[i].x,en[i].y,en[i].val);
            add_edge(en[i].y,en[i].x,en[i].val);
        }
    scanf("%d",&q);
    for(int i=1;i<=n;i++)
        if(!vis[i]) dep[i]=0,va[i][0]=0x3f3f3f3f,dfs(i,i);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(_find(x)!=_find(y))
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",solve(x,y));
    }
    return 0;
}
