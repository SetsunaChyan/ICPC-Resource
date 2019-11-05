#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
ll dp[3005],n,k,ans;

ll fp(ll x,ll y)
{
    ll ret=1;
    while(y)
    {
        if(y&1) ret=ret*x%mod;
        x=x*x%mod,y>>=1;
    }
    return ret;
}

int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1,x;i<n;i++) scanf("%d",&x);
    ll c=1;
    for(int i=k,j=0;i;i--,j++)
    {
        if(j&1) ans-=c*fp(i-1,n-1)%mod*i%mod;
        else ans+=c*fp(i-1,n-1)%mod*i%mod;
        ans=(ans+mod)%mod;
        c=c*i%mod*fp(k-i+1,mod-2)%mod;
    }
    printf("%lld",ans);
    return 0;
}
