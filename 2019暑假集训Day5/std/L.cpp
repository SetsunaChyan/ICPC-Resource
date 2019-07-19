#include<bits/stdc++.h>
using namespace std;
long double n,m,n2;
int t;
int main()
{
    cin>>n>>m;
    if(m==1)n=n+1;
    else if(m==2)n=(n+1)*(n+2)/2;
    else if(m==3)n=(n+1)*(n+2)*(n+3)/6;
    else n=(n+1)*(n+2)*(n+3)*(n+4)/24;
    while(n>=1e17)n/=10,t++;
    printf("%.0Lf",n);
    for(int i=1;i<=t;i++)printf("0");
    return 0;
}