#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,int> pli;
int n,vis[1005];
ll c[1005][1005],dis[1005],ans;
priority_queue<pli,vector<pli>,greater<pli> > q;

void dij(int st)
{
    while(!q.empty()) q.pop();
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        dis[i]=c[st][i];
        if(i==st) dis[i]=0x3f3f3f3f3f3f3f3fll;
        q.push((pli)make_pair(dis[i],i));
    }
    for(int i=1;i<n;i++)
    {
        pli p=q.top();
        q.pop();
        vis[p.second]=1;
        for(int i=0;i<n;i++)
            if(!vis[i]&&p.first+c[p.second][i]<dis[i])
            {
                dis[i]=p.first+c[p.second][i];
                q.push((pli)make_pair(dis[i],i));
            }
    }
}

void solve()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%lld",&c[i][j]);
    dij(0);
    ll cir=dis[0];
    ans=dis[n-1];
    dij(n-1);
    ans=min(ans,dis[n-1]+cir);
    printf("%lld\n",ans);
}

int main()
{
    //虽然我写的是多组，但其实都是单组哒
    while(~scanf("%d",&n)) solve();
    return 0;
}
