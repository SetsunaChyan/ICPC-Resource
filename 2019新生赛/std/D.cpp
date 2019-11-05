#include <bits/stdc++.h>
using namespace std;

int f1,f2,n;
char s[200];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%s",s);
        if(s[0]=='N') f2=1;
        if(s[0]=='C') f1^=1;
    }
    if(f2) printf("not exactly");
    else if(f1) printf("exactly false");
    else printf("exactly true");
    return 0;
}
