#include <bits/stdc++.h>

using namespace std;

inline int read(){
    int sum=0,f=1;char ch=getchar();
    while(ch>'9' || ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){sum=sum*10+ch-'0';ch=getchar();}
    return f*sum;
}

int n,a[10001],f[10001]/*韵脚出现的次数*/;
int c[10001]/*离散化*/;
int ans=0,ok=0;

int main(){
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    memcpy(c,a,sizeof(c));
    sort(c+1,c+n+1);
    int m=unique(c+1,c+n+1)-c;
    for(int i=1;i<=n;i++){
        int k=lower_bound(c+1,c+m+1,a[i])-c;
        a[i]=k;     
    }
    for(int i=1;i<=n;i++){
        f[a[i]]++;
        if(f[a[i]]==2) ok++,f[a[i]]=0/*这里清零是因为可能会是四个一样的韵脚*/;
        if(ok<2) continue;
        ok=0;ans++;
        memset(f,0,sizeof(f));
    }
    printf("%d\n",ans);
    return 0;
}