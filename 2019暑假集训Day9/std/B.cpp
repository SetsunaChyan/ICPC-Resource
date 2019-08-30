#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll dp[1000];

int main()
{
    scanf("%d",&n);
    dp[1]=1;
    for(int i=2;i<=n;i++) dp[i]=i-1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<i;j++)
            dp[i]=max(dp[i],max((ll)i-j,dp[i-j])*max((ll)j,dp[j]));
    printf("%lld",dp[n]);
    return 0;
}
