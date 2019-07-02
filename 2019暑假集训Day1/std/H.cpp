#include <bits/stdc++.h>
using namespace std;

const int MAXN=500005;
int bit[MAXN],a[MAXN],n,m,ans[MAXN],vis[1000005];
struct op
{
    int l,r,pos;
}e[MAXN];

void add(int x,int y) {for(;x<=n;x+=x&-x) bit[x]+=y;}
int sum(int x) {int ret=0; for(;x;x-=x&-x) ret+=bit[x]; return ret;}
bool cmp(op a,op b) {return a.r<b.r;}

int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]++;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
        scanf("%d%d",&e[i].l,&e[i].r),e[i].pos=i;
    sort(e,e+m,cmp);
    int nr=1;
    for(int i=0;i<m;i++)
    {
        for(;nr<=e[i].r;nr++)
        {
            if(vis[a[nr]]) add(vis[a[nr]],-1);
            vis[a[nr]]=nr;
            add(nr,1);
        }
        ans[e[i].pos]=sum(e[i].r)-sum(e[i].l-1);
    }
    for(int i=0;i<m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
