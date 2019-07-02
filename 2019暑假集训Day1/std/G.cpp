#include <bits/stdc++.h>
using namespace std;

int n;
struct node
{
    int par,num,tail;
}bcj[30001];

int _find(int x,int &u)
{
    if(bcj[x].par==x)
    {
        u=0;
        return x;
    }
    else
    {
        bcj[x].par=_find(bcj[x].par,u);
        u+=bcj[x].num;
        bcj[x].num=u;
        return bcj[x].par;
    }
}

void _un(int a,int b)
{
    int t,x=_find(a,t),y=_find(b,t);
    if(x==y) return;
    bcj[y].par=bcj[x].tail;
    bcj[x].tail=bcj[y].tail;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=30000;i++)
        bcj[i].par=i,bcj[i].tail=i,bcj[i].num=1;
    while(n--)
    {
        int a,b,ca,cb;
        char c;
        scanf(" %c%d%d",&c,&a,&b);
        if(c=='C')
            if(_find(a,ca)==_find(b,cb))
                printf("%d\n",abs(ca-cb)-1);
            else
                printf("-1\n");
        else
            _un(a,b);
    }
    return 0;
}
