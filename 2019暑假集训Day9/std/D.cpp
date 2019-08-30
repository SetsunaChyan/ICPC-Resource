#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
int n,m,k,id[102];
ll v[102],dp1[502],dp2[2][502][502],s[502][502];
bool h[102];
vector<ll>v1,v2;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",v+i);
	for(int i=1;i<=k;i++)
		scanf("%d",id+i),v2.push_back(v[id[i]]),h[id[i]]=1;
	for(int i=1;i<=n;i++)
		if(!h[i])
			v1.push_back(v[i]);
	dp1[0]=1;
	for(auto c:v1)
		for(int i=0;i+c<=m;i++)
			dp1[i+c]=(dp1[i+c]+dp1[i])%mod;
	dp2[0][0][m]=1;
	for(int i=1;i<=v2.size();i++)
	{
		memset(dp2[i&1],0,sizeof(dp2[i&1]));
		memset(s,0,sizeof s);
		for(int j=m;j>=0;j--)
			for(int k=m;k>=0;k--)
				s[j][k]=(s[j][k+1]+dp2[~i&1][j][k])%mod;
		auto c=v2[i-1];
		for(int j=m;j>=0;j--)
			for(int k=j/c;k>=0;k--)
				dp2[i&1][j][k]=(dp2[i&1][j][k]+s[j-k*c][k])%mod;
	}
	ll ans=0;
	for(int i=0;i<=m;i++)
	{
		ll t=0;
		for(int j=0;j<=m;j++)
			t=(t+dp2[int(v2.size())&1][m-i][j])%mod;
		ans=(ans+dp1[i]*t)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
