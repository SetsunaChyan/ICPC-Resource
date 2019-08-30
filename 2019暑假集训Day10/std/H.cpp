#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=1e9+7;
char s[100005];
ll a,b,n,ans,l;

int main()
{
    scanf("%s",s);
    n=strlen(s);
    for(int i=0;i<n;i++)
        if(s[i]=='a') ans=(ans+b+1)%mod;
        else if(s[i]=='b') b=ans;
    printf("%lld",ans);
    return 0;
}
