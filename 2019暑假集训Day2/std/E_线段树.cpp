#include <bits/stdc++.h>
using namespace std;

const int MAXN=100005;
int a[MAXN],sum[MAXN<<2],minn[MAXN<<2],maxn[MAXN<<2],n,m;
struct Ret
{
    int sum,minn,maxn;
};

void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
    minn[rt]=min(minn[rt<<1],minn[rt<<1|1]);
    maxn[rt]=max(maxn[rt<<1],maxn[rt<<1|1]);
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        sum[rt]=minn[rt]=maxn[rt]=a[l];
        return;
    }
    int m=l+r>>1;
    if(l<=m) build(rt<<1,l,m);
    if(m<r) build(rt<<1|1,m+1,r);
    pushup(rt);
}

void modify(int rt,int l,int r,int x,int y)
{
    if(l==r)
    {
        sum[rt]=minn[rt]=maxn[rt]=y;
        return;
    }
    int m=l+r>>1;
    if(x<=m) modify(rt<<1,l,m,x,y);
    else modify(rt<<1|1,m+1,r,x,y);
    pushup(rt);
}

Ret query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R)
    {
        Ret ret;
        ret.sum=sum[rt];
        ret.minn=minn[rt];
        ret.maxn=maxn[rt];
        return ret;
    }
    Ret ret,tmp;
    ret.maxn=ret.sum=0,ret.minn=0x3f3f3f3f;
    int m=l+r>>1;
    if(L<=m)
    {
        tmp=query(rt<<1,l,m,L,R);
        ret.sum+=tmp.sum,ret.minn=min(ret.minn,tmp.minn),ret.maxn=max(ret.maxn,tmp.maxn);
    }
    if(m<R)
    {
        tmp=query(rt<<1|1,m+1,r,L,R);
        ret.sum+=tmp.sum,ret.minn=min(ret.minn,tmp.minn),ret.maxn=max(ret.maxn,tmp.maxn);
    }
    return ret;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,1,n);
    while(m--)
    {
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1)
        {
            Ret ans=query(1,1,n,l,r);
            printf("%d\n",ans.sum-ans.maxn-ans.minn);
        }
        else
            modify(1,1,n,l,r);
    }
    return 0;
}


/*
3 6
0 4 10
1 1 3
2 3 2
1 1 3
1 3 3
2 1 10
1 1 3
*/
