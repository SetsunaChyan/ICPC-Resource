#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;
const int mod=10007;
int n,m;
struct node
{
    int lazy_mul,lazy_add,lazy_c,sum[3];
}seg[MAXN<<2];

inline void pushdown(int rt,int lnum,int rnum)
{
    if(seg[rt].lazy_c)
    {
        int &k=seg[rt].lazy_c;
        seg[rt<<1].sum[2]=k*k%mod*k%mod*lnum%mod;
        seg[rt<<1].sum[1]=k*k%mod*lnum%mod;
        seg[rt<<1].sum[0]=k*lnum%mod;
        seg[rt<<1|1].sum[2]=k*k%mod*k%mod*rnum%mod;
        seg[rt<<1|1].sum[1]=k*k%mod*rnum%mod;
        seg[rt<<1|1].sum[0]=k*rnum%mod;
        seg[rt<<1].lazy_add=seg[rt<<1|1].lazy_add=0;
        seg[rt<<1].lazy_mul=seg[rt<<1|1].lazy_mul=1;
        seg[rt<<1].lazy_c=seg[rt<<1|1].lazy_c=k;
        k=0;
    }
    if(seg[rt].lazy_mul!=1)
    {
        int &k=seg[rt].lazy_mul;
        seg[rt<<1].sum[2]=seg[rt<<1].sum[2]*k%mod*k%mod*k%mod;
        seg[rt<<1].sum[1]=seg[rt<<1].sum[1]*k%mod*k%mod;
        seg[rt<<1].sum[0]=seg[rt<<1].sum[0]*k%mod;
        seg[rt<<1|1].sum[2]=seg[rt<<1|1].sum[2]*k%mod*k%mod*k%mod;
        seg[rt<<1|1].sum[1]=seg[rt<<1|1].sum[1]*k%mod*k%mod;
        seg[rt<<1|1].sum[0]=seg[rt<<1|1].sum[0]*k%mod;
        seg[rt<<1].lazy_add=seg[rt<<1].lazy_add*k%mod;
        seg[rt<<1|1].lazy_add=seg[rt<<1|1].lazy_add*k%mod;
        seg[rt<<1].lazy_mul=seg[rt<<1].lazy_mul*k%mod;
        seg[rt<<1|1].lazy_mul=seg[rt<<1|1].lazy_mul*k%mod;
        k=1;
    }
    if(seg[rt].lazy_add)
    {
        int &k=seg[rt].lazy_add;
        seg[rt<<1].sum[2]=(seg[rt<<1].sum[2]+3*k%mod*seg[rt<<1].sum[1]%mod+3*k%mod*k%mod*seg[rt<<1].sum[0]%mod+k*k%mod*k%mod*lnum%mod)%mod;
        seg[rt<<1].sum[1]=(seg[rt<<1].sum[1]+2*k%mod*seg[rt<<1].sum[0]%mod+k*k%mod*lnum%mod)%mod;
        seg[rt<<1].sum[0]=(seg[rt<<1].sum[0]+k*lnum%mod)%mod;
        seg[rt<<1|1].sum[2]=(seg[rt<<1|1].sum[2]+3*k%mod*seg[rt<<1|1].sum[1]%mod+3*k%mod*k%mod*seg[rt<<1|1].sum[0]%mod+k*k%mod*k%mod*rnum%mod)%mod;
        seg[rt<<1|1].sum[1]=(seg[rt<<1|1].sum[1]+2*k%mod*seg[rt<<1|1].sum[0]%mod+k*k%mod*rnum%mod)%mod;
        seg[rt<<1|1].sum[0]=(seg[rt<<1|1].sum[0]+k*rnum%mod)%mod;
        seg[rt<<1].lazy_add=(seg[rt<<1].lazy_add+k)%mod;
        seg[rt<<1|1].lazy_add=(seg[rt<<1|1].lazy_add+k)%mod;
        k=0;
    }
}

inline void pushup(int rt)
{
    for(int i=0;i<3;i++)
        seg[rt].sum[i]=(seg[rt<<1].sum[i]+seg[rt<<1|1].sum[i])%mod;
}

void build(int rt,int l,int r)
{
    seg[rt].lazy_mul=1;
    seg[rt].lazy_add=seg[rt].lazy_c=0;
    if(l==r)
    {
        for(int i=0;i<3;i++)
            seg[rt].sum[i]=0;
        return;
    }
    int m=l+r>>1;
    build(rt<<1,l,m);
    build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int L,int R,int op,int x)
{
    if(L<=l&&r<=R)
    {
        int num=r-l+1;
        if(op==1)
        {
            seg[rt].lazy_add=(seg[rt].lazy_add+x)%mod;
            seg[rt].sum[2]=(seg[rt].sum[2]+3*x%mod*seg[rt].sum[1]%mod+3*x%mod*x%mod*seg[rt].sum[0]%mod+x*x%mod*x%mod*num%mod)%mod;
            seg[rt].sum[1]=(seg[rt].sum[1]+2*x%mod*seg[rt].sum[0]%mod+x*x%mod*num%mod)%mod;
            seg[rt].sum[0]=(seg[rt].sum[0]+x*num%mod)%mod;
        }
        else if(op==2)
        {
            seg[rt].lazy_mul=seg[rt].lazy_mul*x%mod;
            seg[rt].lazy_add=seg[rt].lazy_add*x%mod;
            seg[rt].sum[2]=seg[rt].sum[2]*x%mod*x%mod*x%mod;
            seg[rt].sum[1]=seg[rt].sum[1]*x%mod*x%mod;
            seg[rt].sum[0]=seg[rt].sum[0]*x%mod;
        }
        else if(op==3)
        {
            seg[rt].lazy_mul=1;
            seg[rt].lazy_add=0;
            seg[rt].lazy_c=x;
            seg[rt].sum[2]=x*x%mod*x%mod*num%mod;
            seg[rt].sum[1]=x*x%mod*num%mod;
            seg[rt].sum[0]=x*num%mod;
        }
        return;
    }
    int m=l+r>>1;
    pushdown(rt,m-l+1,r-m);
    if(L<=m) modify(rt<<1,l,m,L,R,op,x);
    if(R>m) modify(rt<<1|1,m+1,r,L,R,op,x);
    pushup(rt);
}

int query(int rt,int l,int r,int L,int R,int op)
{
    if(L<=l&&r<=R)
        return seg[rt].sum[op];
    int m=l+r>>1,ret=0;
    pushdown(rt,m-l+1,r-m);
    if(L<=m) ret+=query(rt<<1,l,m,L,R,op);
    if(R>m) ret+=query(rt<<1|1,m+1,r,L,R,op);
    pushup(rt);
    return ret%mod;
}

void solve()
{
    build(1,1,n);
    while(m--)
    {
        int op,x,y,c;
        scanf("%d%d%d%d",&op,&x,&y,&c);
        if(op==4) printf("%d\n",query(1,1,n,x,y,c-1));
        else modify(1,1,n,x,y,op,c%mod);
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m)&&n&&m) solve();
    return 0;
}
