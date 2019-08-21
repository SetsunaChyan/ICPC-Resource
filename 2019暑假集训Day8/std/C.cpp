#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;
ll sum,cur,ans;
int l1,l2,l;
char s1[200005],s2[200005];

int main()
{
    scanf("%d%d%s%s",&l1,&l2,s1+1,s2+1);
    reverse(s1+1,s1+l1+1);
    reverse(s2+1,s2+l2+1);
    cur=1,sum=ans=0;
    for(int i=1;i<=l2;i++)
    {
        if(i<=l1) sum+=cur*(s1[i]-'0'),sum%=mod;
        ans+=(s2[i]-'0')*(cur*2%mod-1-sum+mod)%mod+sum,ans%=mod;
        if(i<l1) cur=cur*2%mod;
    }
    printf("%lld",ans);
    return 0;
}
