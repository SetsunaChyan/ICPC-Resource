#include <bits/stdc++.h>
using namespace std;

const int MAXN=2005;
const int inf=0x3f3f3f3f;
int n,dp[MAXN],s,t,a[MAXN],ans,cur[MAXN],dis[MAXN];
struct edge
{
    int to,cap,rev;
    edge(int to,int cap,int rev):to(to),cap(cap),rev(rev){}
};
vector<edge> e[MAXN];

void add_edge(int x,int y,int z)
{
    e[x].emplace_back(y,z,e[y].size());
    e[y].emplace_back(x,0,e[x].size()-1);
}

int bfs()
{
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    dis[s]=0;q.push(s);
    while(!q.empty())
    {
        int p=q.front();q.pop();
        for(int i=0;i<e[p].size();i++)
        {
            int to=e[p][i].to;
            if(e[p][i].cap&&dis[p]+1<dis[to])
            {
                dis[to]=dis[p]+1;
                if(to==t) return 1;
                q.push(to);
            }
        }
    }
    return 0;
}

int dfs(int now,int flow)
{
    if(now==t) return flow;
    int rest=flow,k;
    for(int i=cur[now];i<e[now].size();i++)
    {
        int to=e[now][i].to;
        if(e[now][i].cap&&dis[to]==dis[now]+1)
        {
            cur[now]=i;
            k=dfs(to,min(e[now][i].cap,rest));
            e[now][i].cap-=k;
            e[to][e[now][i].rev].cap+=k;
            rest-=k;
        }
    }
    return flow-rest;
}

int dinic()
{
    int ret=0,delta;
    while(bfs())
    {
        memset(cur,0,sizeof(cur));
        while(delta=dfs(s,inf)) ret+=delta;
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++) dp[i]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            if(a[i]>=a[j])
                dp[i]=max(dp[i],dp[j]+1);
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
    if(ans==1)
    {
        printf("%d",n);
        return 0;
    }
    s=0,t=2+2*n;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]==1) add_edge(s,i,inf);
        add_edge(i,i+n,1);
        if(dp[i]==ans) add_edge(i+n,t,inf);
    }
    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            if(dp[i]==dp[j]+1&&a[i]>=a[j])
                add_edge(j+n,i,1);
    printf("%d\n",dinic());
    return 0;
}
