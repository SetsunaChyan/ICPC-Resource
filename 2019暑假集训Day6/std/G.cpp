#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353ll;
int n,m,a[500005];
ll fsum=0,f1[500005],f2[500005],bit1[500005],bit2[500005],ans[500005];
struct node
{
    ll v;
    int pos;
}e[500005];

inline bool cmp(node a,node b){return a.v<b.v;}
inline int lowbit(int x){return x&-x;}

ll fp(ll x,ll y)
{
    ll ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

void dis()
{
    sort(e,e+n,cmp);
    int p=1;
    for(int i=0;i<n;i++)
    {
        if(i&&e[i].v!=e[i-1].v) p++;
        a[e[i].pos]=p;
    }
}

void add(ll bit[],int x,ll y)
{
    for(;x<=n;x+=lowbit(x)) bit[x]=(bit[x]+y)%mod;
}

ll sum(ll bit[],int x)
{
    ll ret=0;
    for(;x>0;x-=lowbit(x)) ret=(ret+bit[x])%mod;
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&e[i].v);
        e[i].pos=i;
    }
    dis();
    memset(bit1,0,sizeof(bit1));
    memset(bit2,0,sizeof(bit2));
    for(int i=0;i<n;i++)
    {
        f1[i]=(sum(bit1,a[i]-1)+1ll)%mod;
        add(bit1,a[i],f1[i]);
        fsum=(fsum+f1[i])%mod;
    }
    for(int i=n-1;i>=0;i--)
    {
        add(bit1,a[i],mod-f1[i]);
        ans[i]=(sum(bit1,a[i]-1)+1ll)*(sum(bit2,n)-sum(bit2,a[i])+mod+1ll)%mod;
        f2[i]=(sum(bit2,n)-sum(bit2,a[i])+1ll+mod)%mod;
        add(bit2,a[i],f2[i]);
    }
    fsum=fp(fsum,mod-2)%mod;
    for(int i=0;i<n;i++)
        printf("%lld ",ans[i]*fsum%mod);
    return 0;
}
