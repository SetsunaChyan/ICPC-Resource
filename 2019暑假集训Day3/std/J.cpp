#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%lld",&a)
#define pr(a) printf("%d",a)
#define per(a,b,c) for(int a=b;a<c;++a)
const int inf=0x3f3f3f3f;
const int mod=2;
int n,m,t,ans=0;
ll hou[5005];
int main()
{
    string s;
    cin>>s;
    int l=s.length();
    for(int i=l-1;i>=0;i--){
        if(s[i]=='Q')
            hou[i]=hou[i+1]+1;
        else
            hou[i]=hou[i+1];
    }
    bool isq=0;
    ll allq=0;
    ll ans=0;
    per(i,0,l){
        if(s[i]=='A'){
            ans+=(allq-isq)*hou[i+2];
        }
        isq=0;
        if(s[i]=='Q')isq=1,allq++;
    }
    cout<<ans<<endl;
}
