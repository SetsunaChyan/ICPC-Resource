#include <bits/stdc++.h>
using namespace std;

int n,a[200005],limit[200005],now=1;
vector<int> dep[200005],e[200005];
priority_queue<int,vector<int>,greater<int> > q;

void dfs(int now,int fa,int d)
{
    dep[d].push_back(now);
    for(auto i:e[now])
        if(i!=fa) dfs(i,now,d+1);
}

int main()
{
    memset(limit,0,sizeof(limit));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),limit[a[i]+1]++;
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,1,1);
    q.push(1);
    while(!q.empty())
    {
        int k=q.top();
        q.pop();
        printf("%d\n",k);
        limit[a[k]+1]--;
        while(!limit[now+1]&&now+1<=n)
        {
            now++;
            for(auto i:dep[now]) q.push(i);
        }
    }
    return 0;
}
