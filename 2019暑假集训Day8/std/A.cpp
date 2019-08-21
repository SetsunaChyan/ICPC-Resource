#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans,sum;
int n;
struct qaq
{
    int a,b;
}e[100005];

bool cmp(qaq x,qaq y){return (double)x.b/x.a>(double)y.b/y.a;}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&e[i].a,&e[i].b),sum+=e[i].b;
    sort(e,e+n,cmp);
    for(int i=0;i<n;i++)
    {
        sum-=e[i].b;
        ans+=sum*e[i].a;
    }
    printf("%lld",ans);
}
