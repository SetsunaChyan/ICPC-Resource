#include <bits/stdc++.h>
using namespace std;

int n,a[10],dp[1000005][9],now,from[1000005][9],sum;

void print(int x,int y)
{
    if(x==0) return;
    if(~from[x][y])
    {
        print(x-1,(y-from[x][y]+9)%9);
        printf("%d",from[x][y]);
    }
    else print(x-1,y);
}

void solve()
{
    sum=0;
    for(int i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum==a[0])
    {
        printf("0\n");
        return;
    }
    for(int i=0;i<=sum;i++)
        for(int j=0;j<9;j++)
            dp[i][j]=0xc0c0c0c0;
    dp[0][0]=0,now=0;
    for(int i=9;i>=0;i--)
        for(int j=0;j<a[i];j++)
        {
            now++;
            for(int k=0;k<=9;k++)
                if(dp[now-1][(k-i+9)%9]+1>=dp[now-1][k])
                    dp[now][k]=dp[now-1][(k-i+9)%9]+1,from[now][k]=i;
                else
                    dp[now][k]=dp[now-1][k],from[now][k]=-1;
        }
    if(dp[now][0]>0)
        print(now,0);
    else
        printf("-1");
    printf("\n");
}

int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}

/*
4
0 1 0 0 1 1 0 0 1 0
1 1 1 1 1 1 1 1 1 1
3 8 0 0 0 0 0 0 1 3
1 1 4 5 1 4 1 9 1 9

1
0 0 0 0 0 1 2 1 1 2

1
0 0 0 0 0 1 2 1 2 0
*/
