#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,d;
ll k,dp[500005],l,r;
struct node
{
    ll x,val;
}e[500005];

bool check(ll g)
{
    deque<int> q;
    memset(dp,0xc0,sizeof(dp));
    dp[0]=0;
    int cur=0;
    ll tp=d+g,ed=max(1ll,d-g);
    for(int i=1;i<=n;i++)
    {
        while(!q.empty()&&e[q.front()].x<e[i].x-tp) q.pop_front();
        while(cur<=n&&e[cur].x<e[i].x-tp) cur++;
        while(cur<=n&&e[cur].x<=e[i].x-ed)
        {
            while(!q.empty()&&dp[q.back()]<=dp[cur]) q.pop_back();
            q.push_back(cur++);
        }
        if(!q.empty()) dp[i]=e[i].val+dp[q.front()];
        if(dp[i]>=k) return true;
    }
    return false;
}

int main()
{
    scanf("%d%d%lld",&n,&d,&k);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&e[i].x,&e[i].val);
    l=0,r=5e15,e[0].x=0;
    while(l<r)
    {
        ll m=l+r>>1;
        if(check(m)) r=m; else l=m+1;
    }
    if(!check(l)) printf("-1"); else printf("%lld",l);
    return 0;
}
