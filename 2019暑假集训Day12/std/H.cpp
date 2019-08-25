#include <bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
int in[maxn],que[maxn],dp[maxn],n,m,head,tail;
 
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>in[i];
	memset(dp,0x7f,sizeof(dp));
	head=tail=1;
	dp[0]=0;
	que[1]=0;
	for(int i=1;i<=n;i++)
	{
		while(head<=tail && que[head]<i-m) head++;//将超出计算范围的队头删除
		dp[i]=dp[que[head]]+in[i];//dp[i]表示i必须选时最小代价
		while(head<=tail && dp[que[tail]]>dp[i]) tail--;//将不必选定i点优的全部删掉
		que[++tail]=i;//将优化值插入队尾 
	}
	int ans=0x7f7f7f7f;
	for(int i=n-m+1;i<=n;i++)
	{
		ans=min(ans,dp[i]);
	} 
	cout<<ans;
	return 0;
}
