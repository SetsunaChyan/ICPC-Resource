#include <bits/stdc++.h>
using namespace std;

int nxt[3100000][2],n,s[31],ans=0,x,tot=1;

void trie_insert(int x)
{
    int p=1;
    for(int i=30;i>=0;i--)
        s[i]=x&1,x>>=1;
    for(int i=0;i<31;i++)
    {
        int c=s[i];
        if(!nxt[p][c]) nxt[p][c]=++tot;
        p=nxt[p][c];
    }
}

int trie_query(int x)
{
    int p=1,ret=0;
    for(int i=30;i>=0;i--)
        s[i]=x&1,x>>=1;
    for(int i=0;i<31;i++)
    {
        int c=s[i]^1;
        ret<<=1;
        if(!nxt[p][c]) c^=1;
        ret|=c;
        p=nxt[p][c];
    }
    return ret;
}

int main()
{
    memset(nxt,0,sizeof(nxt));
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        trie_insert(x);
        ans=max(ans,x^trie_query(x));
    }
    printf("%d",ans);
    return 0;
}
