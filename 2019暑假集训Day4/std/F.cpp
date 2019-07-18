#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m;
struct node{
	int m1,m2,cnt;
	ll sum;
}T[200005<<2];

void tag(int rt,int x)
{
	T[rt].sum-=(ll)(T[rt].m1-x)*T[rt].cnt;
	T[rt].m1=x;
}
void up(int rt)
{
	int l=rt<<1,r=rt<<1|1;
	T[rt].sum=T[l].sum+T[r].sum;
	if(T[l].m1==T[r].m1)
	{
		T[rt].m1=T[l].m1;
		T[rt].cnt=T[l].cnt+T[r].cnt;
		T[rt].m2=max(T[l].m2,T[r].m2);
		return;
	}
	if(T[l].m1<T[r].m1)
		swap(l,r);
	T[rt].m1=T[l].m1;
	T[rt].cnt=T[l].cnt;
	T[rt].m2=max(T[r].m1,T[l].m2);
}
void down(int rt)
{
	int l=rt<<1,r=rt<<1|1;
	if(T[rt].m1<T[rt<<1].m1)
		tag(rt<<1,T[rt].m1);
	if(T[rt].m1<T[rt<<1|1].m1)
		tag(rt<<1|1,T[rt].m1);
}
void update(int l,int r,int x,int L=1,int R=n,int rt=1)
{
	if(x>=T[rt].m1)
		return;
	if(l<=L&&R<=r&&x>T[rt].m2)
	{
		tag(rt,x);
		return;
	}
	down(rt);
	int m=L+R>>1;
	if(l<=m)update(l,r,x,L,m,rt<<1);
	if(r>m)update(l,r,x,m+1,R,rt<<1|1);
	up(rt);
}
ll query(int l,int r,int L=1,int R=n,int rt=1)
{
	if(l<=L&&R<=r)
		return T[rt].sum;
	down(rt);
	ll res=0;
	int m=L+R>>1;
	if(l<=m)res+=query(l,r,L,m,rt<<1);
	if(r>m)res+=query(l,r,m+1,R,rt<<1|1);
	return res;
}
void build(int l,int r,int rt)
{
	if(l==r)
	{
		int t;
		scanf("%d",&t);
		T[rt].sum=T[rt].m1=t;
		T[rt].cnt=1;
		T[rt].m2=-1e9-1;
		return;
	}
	int m=l+r>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	up(rt);
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,n,1);
	while(m--)
	{
		int op,l,r,x;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			scanf("%d",&x);
			update(l,r,x);
		}
		else
			printf("%lld\n",query(l,r));
	}
	return 0;
}
