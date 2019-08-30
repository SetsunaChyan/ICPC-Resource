#include <bits/stdc++.h>
using namespace std;
vector<int> g[200005];
int n,x;
int dfn1[200005],dfnx[200005],ans=0;
void dfs(int u,int from,int tim,int* dfn)
{
	for(auto v:g[u])
		if(v!=from)
			dfn[v]=tim,dfs(v,u,tim+1,dfn);
}
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1,u,v;i<n;i++)
		scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	dfs(1,0,1,dfn1);
	dfs(x,0,1,dfnx);
	for(int i=1;i<=n;i++)
		if(dfnx[i]<dfn1[i])
			ans=max(ans,2*dfn1[i]);
	printf("%d",ans);
	return 0;
}
