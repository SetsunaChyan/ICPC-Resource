#include <bits/stdc++.h>
using namespace std;

int n,a[200005],m;
struct node
{
    int x,t;
}q[200005];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        m=max(a[i],m);
    }
    a[0]=a[n+1]=m;
    int head=0,end=0;
    for(int i=0;i<=n+1;i++)
    {
        int tt=1,flag=0;
        while(head<end&&a[q[end-1].x]<=a[i])
        {
            if(a[q[end-1].x]<a[i]&&(q[end-1].t&1))
            {
                flag=1;
                break;
            }
            tt+=q[end-1].t;
            end--;
        }
        if(flag||i==n+1&&end!=0)
        {
            printf("NO");
            return 0;
        }
        q[end].t=tt;
        q[end].x=i;
        end++;
    }
    printf("YES");
    return 0;
}
