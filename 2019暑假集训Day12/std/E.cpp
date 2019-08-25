#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m,a[11],b[11],d[50005],da[11][50005],db[11][50005];
vector<int>g[50005],q[150005];
ll ans=0;
void bfs(int u,int *dis)
{
	memset(dis,0x3f,sizeof(int)*(n+1));
	dis[u]=0;
	queue<int>q;
	q.push(u);
	while(!q.empty())
	{
		u=q.front();q.pop();
		for(auto v:g[u])
			if(dis[v]>dis[u]+1)
				dis[v]=dis[u]+1,q.push(v);
	}
}
ll bfs()
{
	for(int i=0;i<=3*m;i++)
		q[i].clear();
	for(int i=1;i<=n;i++)
		q[d[i]].push_back(i);
	for(int i=0;i<=3*m;i++)
		for(auto u:q[i])
			if(d[u]==i)
				for(auto v:g[u])
					if(d[v]>d[u]+1)
						d[v]=d[u]+1,q[d[v]].push_back(v);
	ll ret=0;
	for(int i=1;i<=n;i++)
		ret+=d[i];
	return ret;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,a,b);
	for(int i=1,u,v;i<=m;i++)
		scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	for(int i=1;i<=a[0];i++)scanf("%d",a+i),bfs(a[i],da[i]);
	for(int i=1;i<=b[0];i++)scanf("%d",b+i),bfs(b[i],db[i]);
	for(int i=1;i<=a[0];i++)
		for(int j=1;j<=b[0];j++)
		{
			for(int k=1;k<=n;k++)
				d[k]=da[i][k]+db[j][k];
			ans+=bfs();
		}
	ll fm=a[0]*b[0]*n;
	printf("%lld/%lld\n",ans/__gcd(ans,fm),fm/__gcd(ans,fm));
	return 0;
}
