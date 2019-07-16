#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,m,que[10000005],hd,ed;
ll p,q,r,mod,a[10000005],maxrating,cnt;

void gen()
{
    for(int i=k+1;i<=n;i++)
        a[i]=(p*a[i-1]+q*i+r)%mod;
}

void solve()
{
    scanf("%d%d%d%lld%lld%lld%lld",&n,&m,&k,&p,&q,&r,&mod);
    for(int i=1;i<=k;i++)
        scanf("%lld",&a[i]);
    gen();
    maxrating=0,cnt=0;
    hd=ed=0;
    for(int i=1;i<=n;i++)
    {
        if(hd<ed&&que[hd]<=i-m) hd++;
        while(hd<ed&&a[que[ed-1]]<=a[i]) ed--;
        que[ed++]=i;
        if(i>=m) maxrating+=a[que[hd]]^(i-m+1);
    }
    hd=ed=0;
    for(int i=n;i;i--)
    {
        if(hd<ed&&que[hd]>=i+m) hd++;
        while(hd<ed&&a[que[ed-1]]<=a[i]) ed--;
        que[ed++]=i;
        if(i<=n-m+1) cnt+=(ed-hd)^i;
    }
    printf("%lld %lld\n",maxrating,cnt);
}

int main()
{
    solve();
    return 0;
}
