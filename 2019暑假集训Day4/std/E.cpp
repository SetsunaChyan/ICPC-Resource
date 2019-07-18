#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAXN=200005;
int n,q;
ll T[MAXN<<2],lazy[MAXN<<2];
void up(int rt)
{
	T[rt]=T[rt<<1]+T[rt<<1|1];
}
void down(int rt,int l,int r)
{
	if(lazy[rt])
	{
		int m=l+r>>1;
		T[rt<<1]+=lazy[rt]*(m-l+1);
		T[rt<<1|1]+=lazy[rt]*(r-m);
		lazy[rt<<1]+=lazy[rt];
		lazy[rt<<1|1]+=lazy[rt];
		lazy[rt]=0;
	}
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
	down(rt,L,R);
	ll res=0;
	int m=L+R>>1;
	if(l<=m)
		res+=query(l,r,L,m,rt<<1);
	if(m<r)
		res+=query(l,r,m+1,R,rt<<1|1);
	return res;
}
void update(int l,int r,ll x,int L=1,int R=n,int rt=1)
{
	if(l<=L&&R<=r)
	{
		T[rt]+=(R-L+1)*x;
		lazy[rt]+=x;
		return;
	}
	down(rt,L,R);
	int m=L+R>>1;
	if(l<=m)update(l,r,x,L,m,rt<<1);
	if(m<r)update(l,r,x,m+1,R,rt<<1|1);
	up(rt);
}
int main()
{
	scanf("%d%d",&n,&q);
	build();
	while(q--)
	{
		int op,l,r;
		ll x;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
			scanf("%lld",&x),update(l,r,x);
		else
			printf("%lld\n",query(l,r));
	}
	return 0;
}
