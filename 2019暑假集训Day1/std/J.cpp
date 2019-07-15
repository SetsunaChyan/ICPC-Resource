#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=99037660;
ll x[4][4],f[4],n;

void multi(ll x[4][4],ll y[4][4])
{
    ll t[4][4];
    memset(t,0,sizeof(t));
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                t[i][j]+=x[i][k]*y[k][j]%mod,t[i][j]%=mod;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            x[i][j]=t[i][j];
}

void fp(ll x[4][4],ll y)
{
    ll ret[4][4];
    memset(ret,0,sizeof(ret));
    for(int i=0;i<4;i++) ret[i][i]=1;
    while(y)
    {
        if(y&1) multi(ret,x);
        multi(x,x);
        y>>=1;
    }
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            x[i][j]=ret[i][j];
}

int main()
{
    scanf("%lld",&n);
    f[0]=1,f[1]=2,f[2]=4,f[3]=6;
    if(n<=3)
    {
        printf("%lld",f[n]);
        return 0;
    }
    memset(x,0,sizeof(x));
    x[0][0]=x[0][2]=x[0][3]=x[1][0]=x[2][1]=x[3][2]=1;
    fp(x,n-3);
    ll ans=f[3]*x[0][0]%mod+f[2]*x[0][1]%mod+f[1]*x[0][2]%mod+f[0]*x[0][3]%mod;
    printf("%lld",ans%mod);
    return 0;
}
