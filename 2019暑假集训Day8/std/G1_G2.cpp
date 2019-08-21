#include <bits/stdc++.h>
#define y1 y_I_AK_IOI_QAQ_1
using namespace std;

int tot,root[500005],r,c,m,sum[205][205][1005],num[205][205][1005],a[205][205],b[500005];
int x1,y1,x2,y2,h;
struct node
{
    int lc,rc,cnt,sum;
}seg[500005*30];

int build(int l,int r)
{
    int p=++tot;
    if(l==r)
    {
        seg[p].cnt=0;
        seg[p].sum=0;
        return p;
    }
    int m=l+r>>1;
    seg[p].lc=build(l,m);
    seg[p].rc=build(m+1,r);
    seg[p].cnt=seg[seg[p].lc].cnt+seg[seg[p].rc].cnt;
    seg[p].sum=seg[seg[p].lc].sum+seg[seg[p].rc].sum;
    return p;
}

int modify(int rt,int l,int r,int x)
{
    int p=++tot;
    seg[p]=seg[rt];
    if(l==r)
    {
        seg[p].cnt++;
        seg[p].sum+=x;
        return p;
    }
    int m=l+r>>1;
    if(x<=m) seg[p].lc=modify(seg[rt].lc,l,m,x);
    else seg[p].rc=modify(seg[rt].rc,m+1,r,x);
    seg[p].cnt=seg[seg[p].lc].cnt+seg[seg[p].rc].cnt;
    seg[p].sum=seg[seg[p].lc].sum+seg[seg[p].rc].sum;
    return p;
}

int query_sum(int rt,int l,int r,int x)
{
    if(l>=x) return seg[rt].sum;
    if(r<x) return 0;
    int m=l+r>>1,ret=0;
    return query_sum(seg[rt].lc,l,m,x)+query_sum(seg[rt].rc,m+1,r,x);
}

int query_num(int rt,int l,int r,int x)
{
    if(l>=x) return seg[rt].cnt;
    if(r<x) return 0;
    int m=l+r>>1,ret=0;
    return query_num(seg[rt].lc,l,m,x)+query_num(seg[rt].rc,m+1,r,x);
}

inline int check1(int x)
{
    return query_sum(root[y2],1,1000,x)-query_sum(root[y1-1],1,1000,x)>=h;
}

void solve1()
{
    for(int i=1;i<=c;i++)
        scanf("%d",b+i);
    root[0]=build(1,1000);
    for(int i=1;i<=c;i++)
        root[i]=modify(root[i-1],1,1000,b[i]);
    while(m--)
    {
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&h);
        int l=0,r=1000;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(check1(mid)) l=mid; else r=mid-1;
        }
        if(!check1(l))
        {
            printf("-1\n");
            continue;
        }
        int s1=query_sum(root[y2],1,1000,l+1)-query_sum(root[y1-1],1,1000,l+1);
        int num1=query_num(root[y2],1,1000,l+1)-query_num(root[y1-1],1,1000,l+1);
        num1+=(h-s1)/l;
        if((h-s1)%l) num1++;
        printf("%d\n",num1);
    }
}

inline bool check2(int x)
{
    return sum[x2][y2][x]-sum[x1-1][y2][x]-sum[x2][y1-1][x]+sum[x1-1][y1-1][x]>=h;
}

void solve2()
{
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            for(int k=1000;k>=0;k--)
            {
                sum[i][j][k]=sum[i-1][j][k]+sum[i][j-1][k]-sum[i-1][j-1][k]+(a[i][j]>=k)*a[i][j];
                num[i][j][k]=num[i-1][j][k]+num[i][j-1][k]-num[i-1][j-1][k]+(a[i][j]>=k);
            }
    while(m--)
    {
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&h);
        int l=0,r=1000;
        while(l<r)
        {
            int mid=(l+r+1)>>1;
            if(check2(mid)) l=mid; else r=mid-1;
        }
        if(!check2(l))
        {
            printf("-1\n");
            continue;
        }
        int s1=sum[x2][y2][l+1]-sum[x1-1][y2][l+1]-sum[x2][y1-1][l+1]+sum[x1-1][y1-1][l+1];
        int num1=num[x2][y2][l+1]-num[x1-1][y2][l+1]-num[x2][y1-1][l+1]+num[x1-1][y1-1][l+1];
        num1+=(h-s1)/l;
        if((h-s1)%l) num1++;
        printf("%d\n",num1);
    }
}

int main()
{
    scanf("%d%d%d",&r,&c,&m);
    if(r==1) solve1();
    else solve2();
    return 0;
}
