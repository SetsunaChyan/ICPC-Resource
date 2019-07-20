#include <bits/stdc++.h>
using namespace std;
char a[102];
int n;
int check(int s,int e)
{
	int ans=0,i,j;
	for(i=0;i<n;i++)
	{
		for(j=s;j<=e;j++)
			if(a[j]!=a[i+j-s])
				break;
		if(j==e+1)
		{
			++ans;
			i=i+e-s;
		}
		else
			++ans;
	}
	return ans;
}
int main()
{
	scanf("%s",a);
	int i,j,ans=102;
	n=strlen(a);
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)
			ans=min(ans,check(i,j)+(j-i+1));
	printf("%d",min(ans,n));
	return 0;
}

