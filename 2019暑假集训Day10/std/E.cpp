#include<cstdio>
#include<cstring>
using namespace std;

int n,cnt,ans;
bool vis[10005];
int head[10005];
int pre[1000005];

struct Edge{
    int to,nxt;
}edge[2000005];

void add(int x,int y){
    edge[++cnt].to=y;
    edge[cnt].nxt=head[x];
    head[x]=cnt;
}

bool dfs(int now){
    if(vis[now]) return 0;
    vis[now]=1;
    for(int i=head[now];i;i=edge[i].nxt){
        if(!pre[edge[i].to]||dfs(pre[edge[i].to])){
            pre[edge[i].to]=now;
            return 1;
        }
    }
    return 0;
}

signed main(){
    scanf("%d",&n);
    for(int x,y,i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        add(x,i),add(y,i);
    }
    for(int i=1;i<=10000;i++){
        memset(vis,0,sizeof vis);
        if(dfs(i)) ans++;
        else break;
    }
    printf("%d",ans);
    return 0;
}