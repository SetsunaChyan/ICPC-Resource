#include <bits/stdc++.h>
using namespace std;

int fail[200005],tot=1,nxt[200005][26],n,id[200005],ans[200005],len[200005];
vector<int> same[200005];
char s1[200005],s2[200005];

void trie_insert(char s[],int l,int num)
{
    int p=1;
    for(int i=0;i<l;i++)
    {
        int c=s[i]-'a';
        if(!nxt[p][c]) nxt[p][c]=++tot;
        p=nxt[p][c];
    }
    if(id[p]) same[id[p]].push_back(num);
    else id[p]=num;
}

void acatm_build()
{
    int p;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        p=q.front();q.pop();
        for(int i=0;i<26;i++)
            if(nxt[p][i])
            {
                fail[nxt[p][i]]=p==1?1:nxt[fail[p]][i];
                q.push(nxt[p][i]);
            }
            else
                nxt[p][i]=p==1?1:nxt[fail[p]][i];
    }
}

void acatm_match(char s[],int l)
{
    int p=1;
    for(int i=0;i<l;i++)
    {
        int c=s[i]-'a';
        p=nxt[p][c];
        for(int j=p;j!=1;j=fail[j])
            if(id[j]) ans[id[j]]=max(ans[id[j]],max(l-i-1,i+1-len[id[j]]));
    }
}

int main()
{
    scanf("%d%s",&n,s1);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s2);
        trie_insert(s2,len[i]=strlen(s2),i);
    }
    acatm_build();
    acatm_match(s1,strlen(s1));
    for(int i=1;i<=n;i++)
        for(auto j:same[i]) ans[j]=ans[i];
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}
