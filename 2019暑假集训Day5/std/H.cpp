#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x,y;
int bit[100005],n,a[100005],tmp[100005];

int id(int x){return lower_bound(tmp,tmp+n,x)-tmp+1;}
void add(int x){for(;x<=n;x+=x&-x) bit[x]+=1;}
int sum(int x){int ret=0; for(;x;x-=x&-x) ret+=bit[x]; return ret;}

void solve()
{
    for(int i=0;i<n;i++)
        scanf("%d",a+i),tmp[i]=a[i],bit[i+1]=0;
    sort(tmp,tmp+n);
    ll rev=0;
    for(int i=n-1;i>=0;i--)
    {
        rev+=sum(id(a[i])-1);
        add(id(a[i]));
    }
    printf("%lld\n",min(x,y)*rev);
}

int main()
{
    scanf("%d%lld%lld",&n,&x,&y);
    solve();
    return 0;
}
