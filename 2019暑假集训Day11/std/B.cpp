#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=998244353;
int n,m;
int f[20][100005],lg[100005];
int fa(int id,int x)
{ 
	return f[id][x]==x?x:f[id][x]=fa(id,f[id][x]);
}
void up(int a,int b,int id) 
{
	a=fa(id,a),b=fa(id,b);
    if(a!=b)
        f[id][a]=f[id][b];
}
int main() 
{
    scanf("%d%d",&n,&m);
    for(int i=2;i<=n;i++)
		lg[i]=lg[i>>1]+1;
    for(int j=0;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++) 
			f[j][i]=i;
    while(m--)
    {
    	int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        for (int j=lg[r1-l1+1];j>=0;j--)
            if(l1+(1<<j)-1<=r1)
                up(l1,l2,j),l1+=(1<<j),l2+=(1<<j);
    }
    for(int j=lg[n];j;j--) 
	{
        for(int i=1;i+(1<<j)-1<=n;i++)
            up(i,fa(j,i),j-1),up(i+(1<<j-1),f[j][i]+(1<<j-1),j-1);
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        cnt+=fa(0,i)==i;
    ll ans=9;
    while(--cnt)
    	ans=(ans*10)%mod;
    printf("%lld\n", ans);
    return 0;
}
