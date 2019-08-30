#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;
ll e[110][110],ans=0,n,m;
int hd=1,sz=1,fail[110],nxt[110][4],cnt[110];
char s[15];

inline int getval(char x)
{
    if(x=='A') return 0;
    if(x=='C') return 1;
    if(x=='T') return 2;
    return 3; //G
}

void trie_insert(int head,char s[],int len)
{
    int p=head;
    for(int i=0;i<len;i++)
    {
        int c=getval(s[i]);
        if(!nxt[p][c]) nxt[p][c]=++sz;
        p=nxt[p][c];
    }
    cnt[p]=1;
}

void acatm_build(int head)
{
    queue<int> q;
    q.push(head);
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int c=0;c<4;c++)
            if(nxt[p][c])
            {
                fail[nxt[p][c]]=p==head?head:nxt[fail[p]][c];
                q.push(nxt[p][c]);
                cnt[nxt[p][c]]|=cnt[fail[nxt[p][c]]];
            }
            else
                nxt[p][c]=p==head?head:nxt[fail[p]][c];
    }
}

void multi(ll x[110][110],ll y[110][110],int n)
{
    ll tmp[110][110];
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                tmp[i][j]=(tmp[i][j]+x[i][k]*y[k][j]%mod)%mod;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            x[i][j]=tmp[i][j];
}

void fp(ll x[110][110],ll y,int n)
{
    ll ret[110][110];
    memset(ret,0,sizeof(ret));
    for(int i=0;i<n;i++)
        ret[i][i]=1;
    while(y)
    {
        if(y&1) multi(ret,x,n);
        multi(x,x,n);
        y>>=1;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            x[i][j]=ret[i][j];
}

int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        trie_insert(hd,s,strlen(s));
    }
    acatm_build(hd);
    for(int i=0;i<sz;i++)
    {
        int p=i+1;
        if(cnt[p]) continue;
        for(int k=0;k<4;k++)
            if(!cnt[nxt[p][k]]) e[i][nxt[p][k]-1]++;
    }
    fp(e,m,sz);
    for(int i=0;i<sz;i++)
        ans=(ans+e[0][i])%mod;
    printf("%lld",ans);
    return 0;
}
