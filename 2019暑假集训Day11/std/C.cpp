#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100005],ans,sum;
int n;

void solve()
{
    ans=sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",a+i),sum+=a[i];
    if(sum%n!=0)
    {
        printf("-1\n");
        return;
    }
    sum/=n;
    for(int i=0;i<n-1;i++)
    {
        ans=max(ans,abs(sum-a[i]));
        a[i+1]-=sum-a[i];
    }
    printf("%lld\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
