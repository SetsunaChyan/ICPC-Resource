#include<cstdio>
#include<iostream>
using namespace std;
int f[32770][5];
int main()
{
    int i,j,l,n=32768,t,ans;
    f[0][0]=1;
    for(i=1;i*i<=n;i++)
        for(j=i*i;j<=n;j++)
            for(l=1;l<=4;l++)
                f[j][l]+=f[j-i*i][l-1];
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d",&n);
        for(i=1;i<=4;i++)
            ans+=f[n][i];
        printf("%d\n",ans);
    }
    return 0;
}