#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,a[200005];

bool check(int x)
{
    ll tmp=k;
    for(int i=0;i<=n/2;i++)
        if(a[i]<x) tmp-=x-a[i];
    return tmp>=0;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    sort(a,a+n,greater<int>());
    int l=0,r=1e9+5;
    while(l<r)
    {
        int m=(l+r+1)>>1;
        if(check(m)) l=m; else r=m-1;
    }
    printf("%d",l);
    return 0;
}
