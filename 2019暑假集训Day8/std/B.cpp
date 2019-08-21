#include <bits/stdc++.h>
using namespace std;

int n;
double ans;

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
    {
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            ans+=(double)n/i;
        printf("%.3lf\n",ans);
    }

    return 0;
}
