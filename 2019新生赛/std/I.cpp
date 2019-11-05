#include <bits/stdc++.h>
using namespace std;
char s[333];
int n,ans[11],st[11];
int main()
{
	int _;scanf("%d",&_);
	while(_--)
	{
		memset(st,0,sizeof(st));
		scanf("%d%s",&n,s);
		for(int i=0,len=strlen(s),now=1;i<len;i++)
			if(s[i]=='(')
				now++;
			else if(s[i]==')')
				now--;
			else
				ans[s[i]-'0']=st[now-1],st[now]=s[i]-'0';
		for(int i=1;i<=n;i++)
			printf("%d%c",ans[i]," \n"[i==n]);
	}
	return 0;
}

