#include<bits/stdc++.h>
using namespace std;const int N=1<<20|7;typedef long long ll;
ll A[N],B[N];int n,m,i,j,k,len,mid,l,r,ans,on[N];char s[30];
void fwt(ll*x,int n,int flag){
    for(int i=1;i<n;i<<=1)
        for(int p=i<<1,j=0;j<n;j+=p)
            for(int k=0;k<i;++k){
                ll l=x[j+k],r=x[j+k+i];
                if(flag==1)x[j+k]=l+r,x[j+k+i]=(l-r);
                else x[j+k]=(l+r)/2,x[j+k+i]=(l-r)/2;
            }
}
int main(){
    for(scanf("%d%d",&n,&m),len=(1<<m),i=1;i<=n;++i){
        for(scanf("%s",s),k=j=0;j<m;++j)k|=(1<<j)*(s[j]=='1');B[k]++;
    }
    fwt(B,len,1);
    for(i=0;i<len;++i)on[i]=on[i>>1]+(i&1);
    for(l=0,r=m;l<=r;){
        mid=(l+r)>>1;
        for(i=0;i<len;++i)if(on[i]<=mid)A[i]=1;else A[i]=0;
        fwt(A,len,1);for(i=0;i<len;++i)A[i]=A[i]*B[i];fwt(A,len,-1);
        for(i=j=0;i<len;++i)if(A[i]==n){j=1;break;}
        j?(r=(ans=mid)-1):(l=mid+1);
    }printf("%d\n",ans);
}