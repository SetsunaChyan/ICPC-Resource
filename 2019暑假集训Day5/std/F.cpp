#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m,op[100005],l[100005],r[100005],c[100005],ans[100005];
int main()//ans�Ǵ����еĲ������, c�ǲ���Ӧִ�д����Ĳ������
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&op[i],&l[i],&r[i]);
	c[m+1]=1;//ԭc����Ӧ��ȫ1������ֻ��c[m+1]=1����
	for(int i=m;i>=1;i--)
	{
		c[i]=(c[i]+c[i+1])%mod;//�ָ����ò�����Ҫ���Ĵ���
		if(op[i]==1)//1����
			ans[l[i]]=(ans[l[i]]+c[i])%mod,ans[r[i]+1]=(ans[r[i]+1]-c[i]+mod)%mod;//��ans���
		else
			c[r[i]]=(c[r[i]]+c[i])%mod,c[l[i]-1]=(c[l[i]-1]-c[i]+mod)%mod;//��c���
	}
	for(int i=1;i<=n;i++)
		printf("%d%c",ans[i]=(ans[i]+ans[i-1])%mod," \n"[i==n]);
	return 0;
}
