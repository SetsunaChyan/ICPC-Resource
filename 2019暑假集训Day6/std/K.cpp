#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod =1e9+7;
const ll mod2=mod*mod;
int n;
ll f[100005],a,b,x[100005],c[100005];
int main()
{
	scanf("%d%lld%lld%lld%lld",&n,&f[1],&f[2],&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%lld",x+i);
	for(int i=3;i<=n;i++)
		f[i]=(a*f[i-2]+b*f[i-1])%mod;
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		c[l-1]=(c[l-1]+f[1])%mod;
		c[l]=(c[l]+f[2]-b*f[1]+mod2)%mod;
		c[r]=(c[r]+mod2-f[r-l+2])%mod;
		c[r+1]=(c[r+1]+mod2-a*f[r-l+1])%mod;
	}
	for(int i=1;i<=n;i++)
	{	
		if(i==1)
			c[i]=(c[i]+b*c[i-1])%mod;
		else if(i>=2)
			c[i]=(c[i]+a*c[i-2]+b*c[i-1])%mod;
		printf("%lld%c",(x[i]+c[i-1])%mod," \n"[i==n]);
	}
	return 0;
}
