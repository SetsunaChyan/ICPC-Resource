#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1010;
ll in[maxn],n,t,cnt=0,ans=0;
int main()
{
	scanf("%lld%lld",&n,&t);
	for(ll i=0;i<n;i++) scanf("%lld",in+i);
	sort(in,in+n);
	for(ll i=0;i<n;i++)
	{
		cnt=0;
		for(ll j=i+1;j<n;j++)
		{
			if(in[j]-in[i]<=t) cnt++;
			else break;
		}
		ans+=cnt*2;
	}
	printf("%lld",ans);
	return 0;
 } 
