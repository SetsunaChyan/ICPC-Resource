#include <bits/stdc++.h>
using namespace std;
int n,q,a[11][200005],now[100005];
inline int lowbit(int x)
{
	return x&-x;
}
void add(int v,int x,int d)
{
	for(;x<=n;x+=lowbit(x))
		a[v][x]+=d;
}
int sum(int v,int x)
{
	int ans=0;
	for(;x>0;x-=lowbit(x))
		ans+=a[v][x];
	return ans;
}
int solve(int l,int r)
{
	int ans=0;
	int ma=0,mi=10;
	for(int i=0,t;i<=10;i++)
	{
		t=sum(i,r)-sum(i,l-1);
		ans+=t*i;
		if(t)
			ma=max(ma,i),mi=min(mi,i);
	}
	return ans-ma-mi;
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",now+i),add(now[i],i,1);
	while(q--)
	{
		int op,a,b;
		scanf("%d%d%d",&op,&a,&b);
		if(op==1)
			printf("%d\n",solve(a,b));
		else
			add(now[a],a,-1),now[a]=b,add(b,a,1);
	}
	return 0;
}
