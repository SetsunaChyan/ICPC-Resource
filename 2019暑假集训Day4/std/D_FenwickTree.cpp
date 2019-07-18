#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAXN=200005;
int n,q;
ll a[MAXN];
inline int lowbit(int x){return x&-x;}
void update(int x,ll d){for(;x<=n;x+=lowbit(x))a[x]+=d;}
ll query(int x){ll ans=0;for(;x>0;x-=lowbit(x))ans+=a[x];return ans;}
ll query(int l,int r){return query(r)-query(l-1);}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1,t;i<=n;i++)
		scanf("%d",&t),update(i,t);
	while(q--)
	{
		ll op,a,b;
		scanf("%lld%lld%lld",&op,&a,&b);
		if(op==1)
			update(a,b);
		else
			printf("%lld\n",query(a,b));
	}
	return 0;
}
