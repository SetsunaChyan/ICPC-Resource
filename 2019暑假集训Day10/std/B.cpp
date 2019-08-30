#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
#define INF 1000000
const int maxn=100+2;
char in[maxn][maxn];
int d[maxn][maxn],n,m,sx,sy,ex,ey;
int dis[4][2]={0,-1,0,1,-1,0,1,0};
struct lj
{
	int x,y;
	int prex,prey;
}s[maxn][maxn];
//计算起点到终点的最短路径 
void bfs()
{
	queue<P> que;
	while(!que.empty()) que.pop();
	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++) d[i][j]=INF;//初始化距离
	d[sx][sy]=0; 
	que.push(P(sx,sy));//起点压入队列 
    s[sx][sy].x=sx,s[sx][sy].y=sy;
    
	while(!que.empty())
	{
		P u=que.front();
		que.pop();
		if(u.first==ex && u.second==ey) break;
		for(int i=0;i<4;i++)
		{
			int _x=u.first+dis[i][0];
			int _y=u.second+dis[i][1];
			if(_x>=0 && _x<n && _y>=0 && _y<m && in[_x][_y]!='N' && d[_x][_y]==INF)
			{
				que.push(P(_x,_y));
				d[_x][_y]=d[u.first][u.second]+1;
				s[_x][_y].x=_x; 
				s[_x][_y].y=_y;
				s[_x][_y].prex=u.first; 
				s[_x][_y].prey=u.second;
			}
		}
	}
	printf("%d\n",d[ex][ey]); 
}

//打印最短路径路线 
void print_path(int x,int y)
{
    if(x==sx && y==sy)  return;
    int prex = s[x][y].prex;
    int prey = s[x][y].prey;
    print_path(prex,prey);
    if(!(x==ex && y==ey)) printf("%d %d\n",s[x][y].x,s[x][y].y);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",in[i]);
	for(int i=0;i<n;i++)
	 for(int j=0;j<m;j++)
	 {
	 	if(in[i][j]=='S') sx=i,sy=j;//取起点的坐标 
	 	if(in[i][j]=='G') ex=i,ey=j;//取终点的坐标 
	 }
	bfs();
	printf("%d %d\n",sx,sy);
    print_path(ex,ey);
    printf("%d %d",ex,ey);
	return 0;
} 
