#include <bits/stdc++.h>
using namespace std;

int l,bnum;
char s[100005];

void solve()
{
    scanf("%s",s);
    l=strlen(s),bnum=0;
    for(int i=0;i<l;i++) bnum+=s[i]=='B';
    if(bnum<l/2||bnum>=l-1) printf("No\n"); else printf("Yes\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
