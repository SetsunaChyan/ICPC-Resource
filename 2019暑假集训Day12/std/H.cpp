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
		while(head<=tail && que[head]<i-m) head++;//���������㷶Χ�Ķ�ͷɾ��
		dp[i]=dp[que[head]]+in[i];//dp[i]��ʾi����ѡʱ��С����
		while(head<=tail && dp[que[tail]]>dp[i]) tail--;//������ѡ��i���ŵ�ȫ��ɾ��
		que[++tail]=i;//���Ż�ֵ�����β 
	}
	int ans=0x7f7f7f7f;
	for(int i=n-m+1;i<=n;i++)
	{
		ans=min(ans,dp[i]);
	} 
	cout<<ans;
	return 0;
}
