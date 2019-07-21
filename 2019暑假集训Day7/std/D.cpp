#include <bits/stdc++.h>
using namespace std;

int n,ans,z;
vector<int> v[100005];

void dfs(int now,int u,int dep)
{
    if(dep>ans)
    {
        ans=dep;
        z=now;
    }
    for(int i=0;i<v[now].size();i++)
        if(v[now][i]!=u)
            dfs(v[now][i],now,dep+1);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        v[x].push_back(y),v[y].push_back(x);
    }
    dfs(1,1,1);
    dfs(z,z,1);
    ans--;
    if(ans==n-1) printf("1");
    else printf("%d/%d",ans/__gcd(ans,n-1),(n-1)/__gcd(ans,n-1));
    return 0;
}
