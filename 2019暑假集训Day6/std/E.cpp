#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod=1e9+7;
unsigned int dp[100005][3],n;
char s[100005];
int main()
{
	scanf("%s",s);
	n=strlen(s);
	dp[0][0]=1;
	if(s[0]<='2')
		dp[0][s[0]-'0']=1;
	for(int i=1;i<n;i++)
	{
		if(s[i]=='0')
			dp[i][0]=dp[i-1][1]+dp[i-1][2];
		else if(s[i]<='2')
			dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2],
			dp[i][s[i]-'0']=dp[i-1][0];
		else if(s[i]<='6')
			dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
		else
			dp[i][0]=dp[i-1][0]+dp[i-1][1];
		dp[i][0]%=mod;
		dp[i][1]%=mod;
		dp[i][2]%=mod;
	}
	printf("%u\n",dp[n-1][0]);
	return 0;
}
