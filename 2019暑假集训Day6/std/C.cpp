#include <bits/stdc++.h>
using namespace std;
const int maxn=120;
int n,m;
int dp[maxn],a[maxn][maxn];
int main()
{
	while(cin>>n>>m)
	{
		if(n==0 && m==0) break;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		 for(int j=1;j<=m;j++)
		  cin>>a[i][j];
		  
		for(int i=1;i<=n;i++)
		 for(int j=m;j>=0;j--)
		   for(int k=1;k<=m;k++)
		   {
		   	if(j>=k) dp[j]=max(dp[j],dp[j-k]+a[i][k]);
		   }
	    cout<<dp[m]<<'\n';
	}
	return 0;
}
