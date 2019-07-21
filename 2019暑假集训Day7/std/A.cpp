#include <bits/stdc++.h>
using namespace std;

int t,fa[1000005],n;

int _find(int x){return x==fa[x]?x:fa[x]=_find(fa[x]);}
void _merge(int x,int y)
{
    x=_find(x),y=_find(y);
    if(x!=y) fa[x]=y;
}

int main()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=1000000;i++) fa[i]=i;
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d",&x,&y);
        for(int j=1;j<x;j++)
            scanf("%d",&z),_merge(y,z);
    }
    for(int i=1;i<=1000000;i++)
        if(_find(t)==_find(i)) printf("%d ",i);
    return 0;
}
