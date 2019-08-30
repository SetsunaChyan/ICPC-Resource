#include<bits/stdc++.h>
using namespace std;
int k,m,n,nn,t;
int nex[]={1,2,3,0};
int dxy[]={0,-1,0,1,-1,0,-1,0};
int ans[550][550];
int main()
{
	//freopen("o.txt","w",stdout);
    scanf("%d",&nn);
    if(nn==2) {printf("1 3\n1 1\n1 2 1 3\n");return 0;}
    int n=(nn+1)*nn/2;
    int w=(nn+1)/2;
    int h=n/w;
    int x=(nn&1)?1:3;
    int y=1,k=1;
    printf("%d %d\n",h,w);
    for(int i=1;i<=nn;)
    {
    	ans[x][y]=i;
        if(i&1)
        {
            t=0;k=0;
            while(k+1<i)
            {
                k++;
                printf("%d %d ",x,y);
                x+=dxy[t];
                y+=dxy[t+4];
                ans[x][y]=i;
                t=nex[t];
            }
            printf("%d %d\n",x,y);
            x=h-i;
            i++;
            y=w-(i/2)+1;
        }
        else
        {
            int yy=y;
            while(y<=w) ans[x][y]=i,printf("%d %d ",x,y),y++;
            y--;x--;
            while(y>yy) ans[x][y]=i,printf("%d %d ",x,y),y--;
            ans[x][y]=i;
            printf("%d %d\n",x,y);
            i++;
            x=(nn&1)?i:i+2;
            y=(i+1)/2;
        }
    }
    //for(int i=1;i<=h;i++)
    //	for(int j=1;j<=w;j++)
    //		printf("%3d%c",ans[i][j]," \n"[j==w]);
    return 0;
}
