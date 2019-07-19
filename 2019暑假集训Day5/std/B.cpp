#include <bits/stdc++.h>
using namespace std;
const int maxn=20+2;
int dp[maxn][maxn],sum[maxn],in[maxn],n,m;

int main()
{
	memset(dp,0,sizeof(dp));
	cin>>n>>m;
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>in[i];
		sum[i]=sum[i-1]+in[i];
	}
	for(int i=0;i<=n;i++)
	 for(int j=0;j<=m;j++)
	  dp[i][j]=1;
	  
	
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	  for(int k=j-1;k<i;k++)
	  {
	  	dp[i][j]=max(dp[i][j],dp[k][j-1]*(sum[i]-sum[k]));
	  }
	cout<<dp[n][m];
	return 0;
}
