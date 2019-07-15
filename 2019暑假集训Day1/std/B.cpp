#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;
ll a[1000005];


int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    a[0]=0;
    for(int i=1;i<=n;i++)
        a[i]+=a[i-1];
    ll ans=0xc0c0c0c0c0c0c0c0ll;
    for(int i=k;i<=n;i++)
        ans=max(ans,a[i]-a[i-k]);
    printf("%lld",ans);
    return 0;
}
