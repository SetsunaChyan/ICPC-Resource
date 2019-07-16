#include <bits/stdc++.h>
using namespace std;

int cxk[4],n,op[105];

int main()
{
    while(~scanf("%d",&n))
    {
        int flag=1;
        cxk[1]=cxk[2]=1,cxk[3]=0;
        for(int i=0;i<n;i++)
            scanf("%d",&op[i]);
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=1;j<=3;j++)
                if(j!=op[i]) cxk[j]^=1;
            for(int j=1;j<=3;j++) sum+=cxk[j];
            if(sum!=2)
            {
                flag=0;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
