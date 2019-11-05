#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,a[100005],s,e,ans=-2;
int main()
{
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]=(a[i]?-1:1);
	for(int i=1,t=0,ss=1;i<=n;i++)
	{
		t+=a[i];
		if(t>ans)
			ans=t,s=ss,e=i;
		if(t<0)
			t=0,ss=i+1;
	}
	for(int i=s;i<=e;i++)a[i]=-a[i];
	ans=0;
	for(int i=1;i<=n;i++)ans+=a[i]==-1;
	printf("%d\n",ans);
    return 0;
}
