#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isp(ll x)
{
    if(x<=1) return false;
    for(ll i=2;i*i<=x;i++) if(x%i==0) return false;
    return true;
}

int main()
{
    ll n;
    scanf("%lld",&n);
    if(isp(n-2)) printf("2 %lld",n-2);
    else printf("-1");
    return 0;
}
