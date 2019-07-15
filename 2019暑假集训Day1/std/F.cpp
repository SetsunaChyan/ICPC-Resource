#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,m,x1[200005],x2[200005],y1[200005],y2[200005],k[200005],cnt[1000005],ansx,ansy,sum,ans=0;

int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%lld%lld%lld%lld%lld",&x1[i],&y1[i],&x2[i],&y2[i],&k[i]);
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<m;i++)
        cnt[x1[i]]+=k[i],cnt[x2[i]]+=k[i];
    sum=0;
    for(int i=1;i<=1000000;i++)
        if(sum<n&&sum+cnt[i]>=n)
        {
            ansx=i;
            break;
        }
        else
            sum+=cnt[i];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<m;i++)
        cnt[y1[i]]+=k[i],cnt[y2[i]]+=k[i];
    sum=0;
    for(int i=1;i<=1000000;i++)
        if(sum<n&&sum+cnt[i]>=n)
        {
            ansy=i;
            break;
        }
        else
            sum+=cnt[i];
    for(int i=0;i<m;i++)
    {
        if(ansx<x1[i]) ans+=k[i]*(x1[i]-ansx);
        else if(ansx>x2[i]) ans+=k[i]*(ansx-x2[i]);
        if(ansy<y1[i]) ans+=k[i]*(y1[i]-ansy);
        else if(ansy>y2[i]) ans+=k[i]*(ansy-y2[i]);
    }
    printf("%lld",ans);
    return 0;
}
