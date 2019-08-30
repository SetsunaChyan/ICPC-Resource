#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans,mm;
int n,a[1000005];

void solve()
{
    ans=0,mm=0x3f3f3f3f;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i),mm=min(mm,(ll)a[i]);
    for(int i=0;i<n;i++)
        ans+=a[i]-mm;
    printf("%lld %lld\n",ans,ans+mm);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
