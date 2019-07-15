#include <bits/stdc++.h>
using namespace std;

char s[105],tmp[105];

int main()
{
    scanf("%s",s);
    int ans=0,n=strlen(s);
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        {
            int t=0;
            memset(tmp,0,sizeof(tmp));
            for(int k=i;k<=j;k++) tmp[k-i]=s[k];
            char tmp1[105];
            for(int k=0;k<n-(j-i);k++)
            {
                memset(tmp1,0,sizeof(tmp));
                for(int l=k;l<k+(j-i+1);l++)
                    tmp1[l-k]=s[l];
                if(strcmp(tmp1,tmp)==0) t++;
            }
            if(t>=2) ans=max(ans,j-i+1);
        }
    printf("%d",ans);
    return 0;
}

