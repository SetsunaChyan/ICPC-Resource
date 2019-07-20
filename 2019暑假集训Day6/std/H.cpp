#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int head[1005],tot=0,n,m,k,kx[1005],ky[1005],belong[1005],dep[1005],fa[1005][10],lg[1005];
struct edge
{
    int to,nxt;
}e[2005];
struct circle
{
    int x,y,r;
}c[1005];

bool cmp(circle a,circle b){return a.r>b.r;}

void add_edge(int x,int y)
{
    e[tot].to=y;
    e[tot].nxt=head[x];
    head[x]=tot++;
}

void dfs(int now,int f)
{
    dep[now]=dep[f]+1;
    fa[now][0]=f;
    for(int i=1;(1<<i)<=dep[now];i++)
        fa[now][i]=fa[fa[now][i-1]][i-1];
    for(int i=head[now];~i;i=e[i].nxt)
        if(e[i].to!=f) dfs(e[i].to,now);
}

int dis(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    int tx=x,ty=y;
    while(dep[x]>dep[y]) x=fa[x][lg[dep[x]-dep[y]]-1];
    if(x==y) return dep[tx]-dep[ty];
    for(int i=lg[dep[x]]-1;i>=0;i--)
        if(fa[x][i]!=fa[y][i])
            x=fa[x][i],y=fa[y][i];
    x=fa[x][0];
    return -2*dep[x]+dep[tx]+dep[ty];
}

double ddis(ll x1,ll y1,ll x2,ll y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m+1;i++)
        lg[i]=lg[i-1]+(1<<lg[i-1]==i);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&kx[i],&ky[i]);
    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&c[i].r,&c[i].x,&c[i].y);
    sort(c+1,c+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        int flag=0;
        for(int j=i-1;j>=1;j--)
            if(ddis(c[i].x,c[i].y,c[j].x,c[j].y)<=c[j].r-c[i].r)
            {
                add_edge(i,j);
                add_edge(j,i);
                flag=1;
                break;
            }
        if(!flag)
        {
            add_edge(0,i);
            add_edge(i,0);
        }
    }
    for(int i=1;i<=n;i++)
    {
        int flag=0;
        for(int j=m;j>=1;j--)
            if(ddis(kx[i],ky[i],c[j].x,c[j].y)<=c[j].r)
            {
                belong[i]=j;
                flag=1;
                break;
            }
        if(!flag) belong[i]=0;
    }
    dep[0]=0;
    dfs(0,0);
    while(k--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",dis(belong[x],belong[y]));
    }
    return 0;
}

/*
4 3 1000
100 100
0 0
2 2
-2 -2
1 -2 -2
1 2 2
10 0 0
1 2
1 3
1 4
2 3
2 4
3 4
*/
