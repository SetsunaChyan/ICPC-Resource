#include <bits/stdc++.h>
using namespace std;

bool flag;
int n,a[20],used[20],sum;

void dfs(int cur,int last,int len)
{
    if(cur==3)
    {
        flag=true;
        return;
    }
    for(int i=last;i>=0;i--)
    {
        if(used[i]) continue;
        if(a[i]+len>sum) continue;
        used[i]=1;
        if(len+a[i]==sum) dfs(cur+1,n-1,0); else dfs(cur,i-1,len+a[i]);
        if(flag) return;
        used[i]=0;
    }
}

bool solve()
{
    flag=false;
    sum=0;
    memset(used,0,sizeof(used));
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",a+i),sum+=a[i];
    if(sum%4) return false;
    sum/=4;
    for(int i=0;i<n;i++) if(a[i]>sum) return false;
    sort(a,a+n);
    dfs(0,n-1,0);
    return flag;
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--)
        if(solve()) printf("yes\n"); else printf("no\n");
    return 0;
}
