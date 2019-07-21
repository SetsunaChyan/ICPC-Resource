#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,k;
ll mat[105][105];

void mul(ll x[105][105],ll y[105][105])
{
    ll t[105][105];
    memset(t,0,sizeof(t));
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
                t[i][j]+=x[i][k]*y[k][j];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            x[i][j]=t[i][j];
}

void mfp(ll x[105][105],ll y)
{
    ll ret[105][105];
    memset(ret,0,sizeof(ret));
    for(int i=0;i<=n;i++) ret[i][i]=1;
    while(y)
    {
        if(y&1) mul(ret,x);
        mul(x,x);
        y>>=1;
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            x[i][j]=ret[i][j];
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<=n;i++) mat[i][i]=1;
    for(int i=0;i<k;i++)
    {
        int x,y,op;
        scanf("%d%d",&op,&x);
        if(op==1) mat[x][0]++;
        else if(op==2)
            for(int j=0;j<=n;j++)
                mat[x][j]=0;
        else if(op==3)
        {
            scanf("%d",&y);
            ll tmp[105];
            for(int j=0;j<=n;j++) tmp[j]=mat[x][j];
            for(int j=0;j<=n;j++) mat[x][j]=mat[y][j];
            for(int j=0;j<=n;j++) mat[y][j]=tmp[j];
        }
    }
    mfp(mat,m);
    for(int i=1;i<=n;i++)
        printf("%lld ",mat[i][0]);
    return 0;
}
