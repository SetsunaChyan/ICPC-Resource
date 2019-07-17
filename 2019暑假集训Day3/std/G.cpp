#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,c,d,e,l,r,vis[100005];
vector<int> edge[100005],val[100005];

bool check(int level)
{
    memset(vis,0,sizeof(vis));
    ll dis_limit=(ll)d*level,t_limit=(ll)e*level;
    queue<pair<int,ll> > q;
    q.push(make_pair(1,0ll)),vis[1]=1;
    while(!q.empty())
    {
        pair<int,ll> p=q.front();
        q.pop();
        if(p.second==t_limit) continue;
        for(int i=0;i<edge[p.first].size();i++)
            if(!vis[edge[p.first][i]]&&val[p.first][i]<=dis_limit)
                q.push(make_pair(edge[p.first][i],p.second+1ll)),vis[edge[p.first][i]]=1;
    }
    return vis[n];
}

int main()
{
    scanf("%d%d%d%d%d",&n,&m,&c,&d,&e);
    l=0,r=100000;
    while(m--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edge[x].push_back(y),val[x].push_back(z);
        edge[y].push_back(x),val[y].push_back(z);
    }
    while(l<r)
    {
        int mid=l+r>>1;
        if(check(mid)) r=mid; else l=mid+1;
    }
    printf("%d\n",c*l);
    return 0;
}
