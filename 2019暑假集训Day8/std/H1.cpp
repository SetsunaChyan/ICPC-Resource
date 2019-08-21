#include <bits/stdc++.h>
using namespace std;

const int N=2e5+90;
int len1,len2,ne[N],ans;
char t[N],s[N];

void KMP()
{
    for(int i=2,j=0;i<=len2;++i)
    {
        while(j&&s[i]!=s[j+1]) j=ne[i];
        if(s[j+1]==s[i]) j++;
        ne[i]=j;
    }
}

int main()
{
    scanf("%*d%s%s",t+1,s+1);
    len1=strlen(t+1);len2=strlen(s+1);
    KMP();
    for(int i=1,j=0;i<=len1;++i)
    {
         while(j&&t[i]!=s[j+1]) j=ne[j];
         if(t[i]==s[j+1]) j=j+1;
         if(j==len2) ans=max(ans,max(i-j,len1-i)),j=ne[j];
    }
    printf("%d",ans);
    return 0;
}
