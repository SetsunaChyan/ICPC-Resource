#include <bits/stdc++.h>
using namespace std;

int n,a[100005],dp[100005];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        dp[a[i]]=max(dp[a[i]]+1,dp[a[i]-1]+1);
    int ans=n;
    for(int i=1;i<=n;i++)
        ans=min(ans,n-dp[i]);
    printf("%d",ans);
    return 0;
}

