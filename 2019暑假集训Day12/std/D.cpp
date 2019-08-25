#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int s[111111];
int dp[111111][11],sum[111111];///长度为i 结尾为j
///
int main(){
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)){
        for(int i=1;i<=n;i++){
            scanf("%d",s+i);
        }
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        sum[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=i;j>=1&&j>=i-m-1;j--){
                sum[j]+=(sum[j-1]-dp[j][s[i]])%mod;
                sum[j]%=mod;
                dp[j][s[i]]=sum[j-1];
            }
        }
        int ans=sum[n-m]%mod;
        ans+=mod;
        ans%=mod;
        printf("%d\n",ans);
    }
    return 0;
}