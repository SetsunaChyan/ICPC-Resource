#include <bits/stdc++.h>
using namespace std;

int n;
char s[105];

void solve()
{
    scanf("%s",s);
    n=strlen(s);
    if((s[n-1]-'0')&1) s[n-1]--;
    printf("%s\n",s);
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
