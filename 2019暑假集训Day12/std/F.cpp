#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define u second.first
#define v second.second
#define c first
int n,m,fa[200005];
pair<int,pair<int,int>>e[400005];
ll ans=0;
int f(int x){return fa[x]==x?x:fa[x]=f(fa[x]);}
bool merge(int x,int y){x=f(x),y=f(y);if(x!=y)return fa[x]=y,true;return false;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
	for(int i=1,w;i<=n;i++)
		scanf("%d",&w),e[++m].u=0,e[m].v=i,e[m].c=w;
	sort(e+1,e+m+1);
	for(int i=0;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		if(merge(e[i].u,e[i].v))
			ans+=e[i].c;
	printf("%lld\n",ans);
	return 0;
}
