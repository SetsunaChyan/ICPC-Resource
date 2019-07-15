#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans,k,a[14],t;

void solve()
{
    ans=0x3f3f3f3f3f3f3f3fll,t=0;
    scanf("%lld",&k);
    for(int i=0;i<7;i++)
        scanf("%lld",&a[i]),t+=a[i],a[i+7]=a[i];
    if(t==0)
    {
        printf("-1\n");
        return;
    }
    for(int i=0;i<7;i++)
    {
        ll tmp=k/t*7,l=k%t;
        if(l==0) tmp-=7,l+=t;
        for(int j=i;j<i+7;j++)
        {
            if(!l) break;
            tmp++,l-=a[j];
        }
        ans=min(ans,tmp);
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

/*
3
2
0 0 1 0 1 0 0
3
0 0 1 0 1 0 0
1
1 0 0 0 0 0 0
*/
