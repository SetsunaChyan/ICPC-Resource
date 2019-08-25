#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
queue<int>q;
char s[25];
int dis[1<<20];
int n,m,v;
int tmp,nex,mx;
int to(char s[],int len)
{
    int ans=0;
    for(int i=0;i<len;++i)
    ans=ans*2+(s[i]-'0');
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<(1<<m);++i)
        dis[i]=INF;
    for(int i=0;i<n;++i)
    {
        scanf("%s",s);
        v=to(s,m);
        dis[v]=0;
        q.push(v);
    }
    while(!q.empty())
    { 
        tmp=q.front();q.pop();
        for(int i=0;i<m;++i)
        {
            nex=tmp^(1<<i);
            if(dis[nex]>dis[tmp]+1)
            {
                dis[nex]=dis[tmp]+1;
                q.push(nex);
            }
        }
    }
      
    for(int i=0;i<(1<<m);++i)
    mx=max(mx,dis[i]);
    printf("%d\n",m-mx);
    return 0;
}