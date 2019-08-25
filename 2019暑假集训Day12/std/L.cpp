#include <bits/stdc++.h>
using namespace std;

int n,l,r;

int main()
{
    scanf("%d",&n);
    l=1,r=n;
    while(l<r)
    {
        printf("? %d %d\n",l,r);
        fflush(stdout);
        scanf("%d",&n);
        if(n) l++; else r--;
    }
    printf("! %d\n",l);
    fflush(stdout);
    return 0;
}
