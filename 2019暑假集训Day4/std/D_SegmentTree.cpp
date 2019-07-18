#include <bits/stdc++.h>
using namespace std;
const int MAXN=200005;
typedef long long int ll;
int n,q;
ll T[MAXN<<2];
void up(int rt)
{
	T[rt]=T[rt<<1]+T[rt<<1|1];
}
void build(int l=1,int r=n,int rt=1)
{
	if(l==r)
	{
		scanf("%lld",&T[rt]);
		return;
	}
	int m=l+r>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	up(rt);
}
ll query(int l,int r,int L=1,int R=n,int rt=1)
{
	if(l<=L&&R<=r)
		return T[rt];
	ll res=0;
	int m=L+R>>1;
	if(l<=m)
		res+=query(l,r,L,m,rt<<1);
	if(m<r)
		res+=query(l,r,m+1,R,rt<<1|1);
	return res;
}
void update(int p,ll x,int L=1,int R=n,int rt=1)
{
	if(L==R)
	{
		T[rt]+=x;
		return;
	}
	int m=L+R>>1;
	if(p<=m)update(p,x,L,m,rt<<1);
	if(m<p)update(p,x,m+1,R,rt<<1|1);
	up(rt);
}
int main()
{
	scanf("%d%d",&n,&q);
	build();
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
