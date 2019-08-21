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
set<int> s;
int _,n,m,k;
int a[100001];
int f[100001];
int dp[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    per(i,0,n)cin>>a[i];
    f[0]=1;
    dp[0]=1;
    per(i,1,n){
        f[i]=inf;
        dp[i]=inf;
        s.clear();
        for(int j=i;j>=0;--j){
            s.insert(a[j]);
            if(s.size()>k)
                break;
            f[i]=min(f[i],f[j-1]+1);
            dp[i]=min(dp[i],dp[j-1]+(int)s.size());
        }
    }
    cout<<f[n-1]<<endl;
    cout<<dp[n-1]<<endl;

}