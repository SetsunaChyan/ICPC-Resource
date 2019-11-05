#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m,a[55][55];
ll ans;
ll gao(int x)
{
	return (1LL<<x)-1;
}
int main()
{
	scanf("%d%d",&n,&m);for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",a[i]+j);
	for(int i=1;i<=n;i++)
	{
		int c=0;
		for(int j=1;j<=m;j++)
			c+=a[i][j];
		ans+=gao(c)+gao(m-c);
	}
	for(int j=1;j<=m;j++)
	{
		int c=0;
		for(int i=1;i<=n;i++)
			c+=a[i][j];
		ans+=gao(c)+gao(n-c);
	}
	printf("%lld\n",ans-n*m);
    return 0;
}

