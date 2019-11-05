#include <bits/stdc++.h>
using namespace std;

int n,a;
long long sum=0;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a),sum+=a;
    if(sum%n==0) puts("YES");
    else puts("NO");
    return 0;
}
