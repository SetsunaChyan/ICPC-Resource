#include <bits/stdc++.h>
using namespace std;

int n,m,x[2005],y[2005],tot=0,s[4000005];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&x[i]);
    for(int i=0;i<m;i++) scanf("%d",&y[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(x[i]-y[j]>=0) s[tot++]=x[i]-y[j];
    if(tot<=0) {printf("0\n");return 0;}
    sort(s,s+tot);
    if(s[0]) {printf("0\n");return 0;}
    for(int i=1;i<tot;i++)
        if(s[i]!=s[i-1]+1&&s[i]!=s[i-1])
        {
            printf("%d\n",s[i-1]+1);
            return 0;
        }
    printf("%d\n",s[tot-1]+1);
    return 0;
}
