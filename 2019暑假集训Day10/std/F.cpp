#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f
#define re register
#define N 200057
#define mod 376544743
#define inv2 188272372
using namespace std;

inline int read(){
    int x=0,w=0;char ch=getchar();
    while (!isdigit(ch))w|=ch=='-',ch=getchar();
    while (isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
    return w?-x:x;
}
int w[N],ans;
signed main(){
    //freopen("9.in","r",stdin);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n;++i)cin>>w[i];
    if (n*m<=1e7){
        for (int i=1;i<=m;++i){
            int flag=0;
            for (int j=1;j<=n;++j)
                if (i%w[j]==0){
                    flag=1;
                    break;
                }
            if (flag)ans=(ans+i)%mod;
        }
        printf("%d\n",ans);
        return 0;
    }
    for (int s=1;s<(1<<n);++s){
        int res=1,cnt=0;
        for (int j=1;j<=n;++j)
            if (s&(1<<(j-1)))
                res*=w[j],++cnt;
        int t=m/res;
        if (cnt&1)ans=(ans+res*t%mod*(t+1)%mod*inv2%mod)%mod;
        else ans=(ans-res*t%mod*(t+1)%mod*inv2%mod)%mod;
    }
    cout<<(ans<0?ans+mod:ans)<<endl;
    return 0;
}