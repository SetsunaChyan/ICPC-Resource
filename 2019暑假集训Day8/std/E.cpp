#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%lld",&a)
#define pr(a) printf("%d",a)
#define per(a,b,c) for(int a=b;a<c;++a)
#define perr(a,b,c) for(int a=b;a<=c;++a)
const int inf=0x3f3f3f3f;
const int mod=2;

int _,n;

int main()
{
    
    {
        sd(n);
        double ans=0;
        per(i,0,n){

            ans+=1.0*n/(n-i);
            //printf("%.3f\n",1.0*n/(n-i));
        }
        printf("%.0f\n",ans);
    }
}