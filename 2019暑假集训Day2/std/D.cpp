#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l,r,k;

void solve()
{
    scanf("%lld%lld%lld",&l,&r,&k);
    if(k&1) printf("%lld\n",r-l+1);
    else printf("%lld\n",r-l+1-(r+1)/(k+1)+l/(k+1));
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
