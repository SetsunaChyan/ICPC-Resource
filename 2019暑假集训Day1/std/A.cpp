#include <bits/stdc++.h>
using namespace std;

int n,m,k,dp[1005][1005];

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    memset(dp,0,sizeof(dp));
    while(n--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        for(int i=m;i>=x;i--)
            for(int j=k;j>=y;j--)
                dp[i][j]=max(dp[i][j],dp[i-x][j-y]+1);
    }
    printf("%d",dp[m][k]);
    return 0;
}
