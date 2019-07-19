#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,c[100005];
vector<int>v[100005];
ll pre[100005];
int main()
{
	char str[80];
	for(int T=1;T<=1;T++)
	{
		sprintf(str,"%d.in",T);
		//freopen(str,"r",stdin);
		sprintf(str,"%d.out",T);
		//freopen(str,"w",stdout);
		int _;scanf("%d",&_);
		while(_--)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
				scanf("%d",c+i);
			int mak=0;
			for(int i=1,k;i<=n;i++)
			{
				v[i].clear();
				scanf("%d",&k);
				mak=max(mak,k);
				if(!k)continue;
				for(int j=1,t;j<=k;j++)
					scanf("%d",&t),v[i].push_back(t);
				sort(v[i].begin(),v[i].end(),greater<int>());
			}
			memset(pre,0,sizeof(ll)*(mak+2));
			for(int i=1,k;i<=n;i++)
			{
				ll sum=0;
				for(int j=0;j<v[i].size();j++)
				{
					sum+=v[i][j];
					if(j+1==c[i])
						pre[j+1]+=sum;
					else if(j+1>c[i])
						pre[j+1]+=v[i][j];
				}
			}

			for(int i=1;i<=mak;i++)
				pre[i]+=pre[i-1];
			ll ans=pre[1],ansi=1;
			for(int i=2;i<=mak;i++)
				if(i*ans<ansi*pre[i])
					ans=pre[i],ansi=i;
			printf("%lld/%lld\n",ans/__gcd(ans,ansi),ansi/__gcd(ans,ansi));
		}
	}
	return 0;
}
