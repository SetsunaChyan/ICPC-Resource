#include <bits/stdc++.h>
using namespace std;

int a,b;

void solve()
{
    int ans=0;
    scanf("%d%d",&a,&b);
    while(a!=b)
    {
        if(a<b) swap(a,b);
        a>>=1;
        ans++;
    }
    printf("%d\n",ans);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
}
