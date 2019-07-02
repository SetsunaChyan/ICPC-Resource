#include <bits/stdc++.h>
using namespace std;

//n=3e5 m=3e5
int t[3],flag,n,m,tot=0,head[300005],vis[300005],ans=0;
vector<int> e[300005];

void dfs(int now,int col)
{
    vis[now]=col,t[col]++;
    for(int i=0;i<e[now].size();i++)
        if(!vis[e[now][i]])
            dfs(e[now][i],3-col);
        else if(vis[e[now][i]]==col)
            flag=0;
}

int main()
{
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[y].push_back(x);
        e[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        t[1]=t[2]=0,flag=1;
        dfs(i,1);
        if(!flag)
        {
            printf("QAQ");
            return 0;
        }
        ans+=min(t[1],t[2]);
    }
    printf("%d",ans);
    return 0;
}
