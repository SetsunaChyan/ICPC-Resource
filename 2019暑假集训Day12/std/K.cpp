#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans;
int pre[100005],suf[100005],n;
char s[100005];

void solve()
{
    scanf("%s",s+1);
    n=strlen(s+1);
	ans=0;
	for(int i=1;i<=n;i++)
        if(s[i]=='1') pre[i]=0;
        else pre[i]=pre[i-1]+1;
	for(int i=n;i;i--)
        if(s[i]=='1') suf[i]=0;
        else suf[i]=suf[i+1]+1;
    for(int i=1;i<=n;i++)
    {
        if(pre[i]<=suf[i]) ans+=2*pre[i]+1;
        else ans+=pre[i]+suf[i]+2;
    }
    printf("%lld\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
