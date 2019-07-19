#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,op[100005],l[100005],r[100005],c[100005],ans[100005];
int main()//ans是答案序列的差分数组, c是操作应执行次数的差分数组
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&op[i],&l[i],&r[i]);
	c[m+1]=1;//原c数组应是全1，因差分只需c[m+1]=1即可
	for(int i=m;i>=1;i--)
	{
		c[i]=(c[i]+c[i+1])%mod;//恢复出该操作需要做的次数
		if(op[i]==1)//1操作
			ans[l[i]]=(ans[l[i]]+c[i])%mod,ans[r[i]+1]=(ans[r[i]+1]-c[i]+mod)%mod;//给ans打标
		else
			c[r[i]]=(c[r[i]]+c[i])%mod,c[l[i]-1]=(c[l[i]-1]-c[i]+mod)%mod;//给c打标
	}
	for(int i=1;i<=n;i++)
		printf("%d%c",ans[i]=(ans[i]+ans[i-1])%mod," \n"[i==n]);
	return 0;
}
