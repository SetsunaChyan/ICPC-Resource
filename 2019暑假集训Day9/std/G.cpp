#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e5+5;
const int inf=0x7fffffff;
int n,op,x;

namespace Treap
{
    int tot,root;
    struct node
    {
        int cnt,val,dat,siz,lc,rc;
    }bst[MAXN];

    inline void pushup(int rt)
    {
        bst[rt].siz=bst[rt].cnt;
        if(bst[rt].lc) bst[rt].siz+=bst[bst[rt].lc].siz;
        if(bst[rt].rc) bst[rt].siz+=bst[bst[rt].rc].siz;
    }

    inline void zig(int &rt)
    {
        int p=bst[rt].lc;
        bst[rt].lc=bst[p].rc;
        bst[p].rc=rt;
        rt=p;
        pushup(bst[rt].rc);pushup(rt);
    }

    inline void zag(int &rt)
    {
        int p=bst[rt].rc;
        bst[rt].rc=bst[p].lc;
        bst[p].lc=rt;
        rt=p;
        pushup(bst[rt].lc);pushup(rt);
    }

    int new_node(int val)
    {
        bst[++tot].val=val;
        bst[tot].dat=rand();
        bst[tot].siz=bst[tot].cnt=1;
        bst[tot].lc=bst[tot].rc=0;
        return tot;
    }

    void build()
    {
        new_node(-inf);new_node(inf);
        root=1,bst[1].rc=2;
        pushup(1);
    }

    void _insert(int &rt,int val)
    {
        if(rt==0)
        {
            rt=new_node(val);
            return;
        }
        if(bst[rt].val==val)
        {
            bst[rt].cnt++;
            pushup(rt);
            return;
        }
        if(val<bst[rt].val)
        {
            _insert(bst[rt].lc,val);
            if(bst[rt].dat<bst[bst[rt].lc].dat) zig(rt);
        }
        else
        {
            _insert(bst[rt].rc,val);
            if(bst[rt].dat<bst[bst[rt].rc].dat) zag(rt);
        }
        pushup(rt);
    }

    void _delete(int &rt,int val)
    {
        if(rt==0) return;
        if(bst[rt].val==val)
        {
            if(bst[rt].cnt>1)
            {
                bst[rt].cnt--;
                pushup(rt);
                return;
            }
            if(bst[rt].rc||bst[rt].lc)
            {
                if(bst[rt].rc==0||bst[bst[rt].rc].dat<bst[bst[rt].lc].dat)
                    zig(rt),_delete(bst[rt].rc,val);
                else
                    zag(rt),_delete(bst[rt].lc,val);
                pushup(rt);
            }
            else rt=0;
            return;
        }
        if(val<bst[rt].val) _delete(bst[rt].lc,val);
        else _delete(bst[rt].rc,val);
        pushup(rt);
    }

    int getPrev(int val)
    {
        int ret=1,rt=root;
        while(rt)
        {
            if(bst[rt].val==val)
            {
                if(bst[rt].lc)
                {
                    rt=bst[rt].lc;
                    while(bst[rt].rc) rt=bst[rt].rc;
                    ret=rt;
                }
                break;
            }
            if(bst[rt].val<val&&bst[rt].val>bst[ret].val) ret=rt;
            if(val<bst[rt].val) rt=bst[rt].lc;
            else rt=bst[rt].rc;
        }
        return bst[ret].val;
    }

    int getNext(int val)
    {
        int ret=2,rt=root;
        while(rt)
        {
            if(bst[rt].val==val)
            {
                if(bst[rt].rc)
                {
                    rt=bst[rt].rc;
                    while(bst[rt].lc) rt=bst[rt].lc;
                    ret=rt;
                }
                break;
            }
            if(bst[rt].val>val&&bst[rt].val<bst[ret].val) ret=rt;
            if(val<bst[rt].val) rt=bst[rt].lc;
            else rt=bst[rt].rc;
        }
        return bst[ret].val;
    }

    int getRank(int rt,int val)
    {
        if(rt==0) return 0;
        if(val==bst[rt].val) return bst[bst[rt].lc].siz+1;
        if(val<bst[rt].val) return getRank(bst[rt].lc,val);
        else return bst[bst[rt].lc].siz+bst[rt].cnt+getRank(bst[rt].rc,val);
    }

    int getVal(int rt,int k)
    {
        if(rt==0) return inf;
        if(bst[bst[rt].lc].siz>=k) return getVal(bst[rt].lc,k);
        if(bst[bst[rt].lc].siz+bst[rt].cnt>=k) return bst[rt].val;
        return getVal(bst[rt].rc,k-bst[bst[rt].lc].siz-bst[rt].cnt);
    }
}

int main()
{
    using namespace Treap;
    srand(time(0));
    build();
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&op,&x);
        if(op==1) _insert(root,x);
        else if(op==2) _delete(root,x);
        else if(op==3) printf("%d\n",getRank(root,x)-1);
        else if(op==4) printf("%d\n",getVal(root,x+1));
        else if(op==5) printf("%d\n",getPrev(x));
        else if(op==6) printf("%d\n",getNext(x));
    }
    return 0;
}
