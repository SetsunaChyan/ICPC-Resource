#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100005],add=0;
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    while(m--)
    {
        int op,x,y;
        scanf("%d%d",&op,&x);
        if(op==1)
        {
            scanf("%d",&y);
            a[x]=y-add;
        }
        else if(op==2)
            add+=x;
        else
            printf("%lld\n",a[x]+add);
    }

    return 0;
}


/*
10 11
1 2 3 4 5 6 7 8 9 10
3 2
3 9
2 10
3 1
3 10
1 1 10
2 10
2 10
3 1
3 10
3 9
*/
