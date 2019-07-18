#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll seg[200005<<2],m,d,t=0,l=0;

inline void pushup(int rt)
{
    seg[rt]=max(seg[rt<<1],seg[rt<<1|1]);
}

void build(int rt,int l,int r)
{
    if(l==r)
    {
        seg[rt]=0;
        return;
    }
    int m=l+r>>1;
    if(l<=m) build(rt<<1,l,m);
    if(m<r) build(rt<<1|1,m+1,r);
}

void modify(int rt,int l,int r,int x,ll y)
{
    if(l==r)
    {
        seg[rt]=y;
        return;
    }
    int m=l+r>>1;
    if(x<=m) modify(rt<<1,l,m,x,y);
    else modify(rt<<1|1,m+1,r,x,y);
    pushup(rt);
}

ll query(int rt,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) return seg[rt];
    int m=l+r>>1;
    ll ret=0xc0c0c0c0c0c0c0c0LL;
    if(L<=m) ret=max(ret,query(rt<<1,l,m,L,R));
    if(m<R) ret=max(ret,query(rt<<1|1,m+1,r,L,R));
    return ret;
}

int main()
{
    scanf("%lld%lld",&m,&d);
    build(1,1,m);
    for(int i=0;i<m;i++)
    {
        char op;ll n;
        scanf(" %c%lld",&op,&n);
        if(op=='A')
            modify(1,1,m,++l,(t+n+d)%d);
        else
            printf("%lld\n",t=query(1,1,m,l-n+1,l));
    }
    return 0;
}
