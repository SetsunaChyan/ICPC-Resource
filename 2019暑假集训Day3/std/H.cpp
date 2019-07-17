#include <bits/stdc++.h>
using namespace std;

struct node
{
    node* nxt[2];
    int val,dep;
}head;

int ans,n;
char s[205];

void del(node* p)
{
    if(p->nxt[0]) del(p->nxt[0]);
    if(p->nxt[1]) del(p->nxt[1]);
    if(p!=&head) free(p);
}

node* newnode(int d)
{
    node* p=(node*)malloc(sizeof(node));
    p->dep=d+1;
    p->val=0;
    p->nxt[0]=p->nxt[1]=0;
    return p;
}

void trie_insert(char s[],int l)
{
    node* p=&head;
    for(int i=0;i<l;i++)
    {
        int c=s[i]-'0';
        if(p->nxt[c]==NULL) p->nxt[c]=newnode(p->dep);
        p=p->nxt[c];
        p->val++;
        ans=max(ans,p->dep*p->val);
    }
}

void solve()
{
    head.val=head.dep=0;
    head.nxt[0]=head.nxt[1]=0;
    ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        trie_insert(s,strlen(s));
    }
    del(&head);
    printf("%d\n",ans);
}

int main()
{
    //int _;
    //scanf("%d",&_);
    //while(_--)
    solve();
    return 0;
}

/*
4
4
0000
0001
10101
010
2
01010010101010101010
11010010101010101010
3
010101010101000010001010
010101010101000010001000
010101010101000010001010
5
01010101010100001010010010100101
01010101010100001010011010101010
00001010101010110101
0001010101011010101
00010101010101001
*/
