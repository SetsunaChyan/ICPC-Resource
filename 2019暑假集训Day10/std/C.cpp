#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node {
    int to;
    ll val;
    int nxt;
}e[200005];
int head[500005], cnt;
int A,B,C,D,E,T,n,l,r;
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
ll dis[500005],ans=2e18;

void add(int u,int v,ll w)
{
    e[cnt]=(node){v,w,head[u]};
    head[u]=cnt++;
    e[cnt]=(node){u,w,head[v]};
    head[v]=cnt++;
}

ll Dijkstra(int s,int t)
{
    memset(dis,0x3f,sizeof dis);
    q.push(make_pair(0,s));
    dis[s]=0;
    while(!q.empty()) 
	{
        int u=q.top().second;q.pop();
        for (int i=head[u];~i;i=e[i].nxt)
            if (dis[e[i].to]>dis[u]+e[i].val) 
			{
                dis[e[i].to]=dis[u]+e[i].val;
                q.push(make_pair(dis[e[i].to],e[i].to));
            }
    }
    return dis[t];
}

int main() 
{
    memset(head,-1,sizeof head);
    scanf("%d%d%d%d%d%d",&A,&B,&C,&D,&E,&n);
    B+=A;C+=B;D+=C;E+=D;
    ++A;++B;++C;++D;
    for(int i=1,l,r;i<=n;i++)
		scanf("%d%d",&l,&r),add(l,r+1,r-l+1);
    ans=min(ans,Dijkstra(A,B)+Dijkstra(C,D));
    ans=min(ans,Dijkstra(A,C)+Dijkstra(B,D));
    ans=min(ans,Dijkstra(A,D)+Dijkstra(B,C));
    printf("%lld\n",ans==2e18?-1:ans);
    return 0;
}
