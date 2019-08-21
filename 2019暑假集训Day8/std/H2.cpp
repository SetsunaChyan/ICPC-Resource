#include <bits/stdc++.h>
using namespace std;

int l1,l2,dp1[200005],dp2[200005],ans,cur;
char s[200005],t[200005];

int main()
{
    scanf("%s%s",s,t);
    l1=strlen(s),l2=strlen(t);
    cur=0;
    for(int i=0;i<l1;i++)
    {
        if(s[i]==t[cur]) dp1[cur++]=i;
        if(cur>=l2) break;
    }
    cur=l2-1;
    for(int i=l1-1;i>=0;i--)
    {
        if(s[i]==t[cur]) dp2[cur--]=i;
        if(cur<0) break;
    }
    ans=max(dp1[0],l1-dp2[l2-1]-1);
    ans=max(ans,l1-dp1[l2-1]-1);
    ans=max(ans,dp2[0]);
    for(int i=0;i<l2-1;i++)
        ans=max(ans,dp2[i+1]-dp1[i]-1);
    printf("%d",ans);
    return 0;
}
