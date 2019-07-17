#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000000
ll k,n,sum;
ll quick_pow(ll a,ll b)
{
    ll ans=1;
	while(b)
	{
		if(b&1) ans=(a%mod)*(ans%mod)%mod;
		a=(a%mod)*(a%mod)%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	cin>>k>>n;
	sum=(quick_pow(n,k)-n*quick_pow(n-1,k-1)%mod)%mod;
	if(sum<0) sum=mod+sum;
	cout<<sum;
	return 0;
}
