#include<bits/stdc++.h>
using namespace std;
double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double f(double x,double y,double x1,double y1,double x2,double y2)//圆心到矩形边的距离最小值
{
    if(x1==x2)
    {
        if(y<=max(y1,y2)&&y>=min(y1,y2))
        {
            return fabs(x-x1);
        }else
        {
        double b=dis(x,y,x1,y1);
        double c=dis(x,y,x2,y2);
        double result=min(b,c);
        return result;
        }
    }else if(y1==y2)
    {
        if(x<=max(x1,x2)&&x>=min(x1,x2))
        {
            return fabs(y-y1);
        }else
        {
        double b=dis(x,y,x1,y1);
        double c=dis(x,y,x2,y2);
        double result=min(b,c);
        return result;
        }
    }
}
int main()
{
    double x,y,r,x1,y1,x2,y2;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf",&x,&y,&r,&x1,&y1,&x2,&y2);
        double x3=x1,y3=y2;
        double x4=x2,y4=y1;
        double l1=f(x,y,x1,y1,x3,y3);
        double l2=f(x,y,x1,y1,x4,y4);
        double l3=f(x,y,x2,y2,x3,y3);
        double l4=f(x,y,x2,y2,x4,y4);

        double L=min(l1,min(l2,min(l3,l4)));

        double r1=dis(x,y,x1,y1);
        double r2=dis(x,y,x2,y2);
        double r3=dis(x,y,x3,y3);
        double r4=dis(x,y,x4,y4);

        double R=max(r1,max(r2,max(r3,r4)));

        if(L>r)
            printf("NO\n");
        else if(R<r)
            printf("NO\n");
        else if(L<=r&&R>=r)
            printf("YES\n");
    }
    return 0;
}