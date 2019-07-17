#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll m,pp[100005],cc[100005];
int n,k;
priority_queue<pair<ll,int>>p,c;
priority_queue<ll>pc;
bool h[100005];
int main()
{
	scanf("%d%lld%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",pp+i,cc+i),p.emplace(-pp[i],i),c.emplace(-cc[i],i);
	for(int i=1;i<=k;i++)
		pc.push(0);
	for(int i=0;i<n&&m>=0;i++)
	{
		while(!p.empty()&&h[p.top().second])p.pop();
		while(!c.empty()&&h[c.top().second])c.pop();
		if(-pc.top()+-c.top().first<-p.top().first)
		{
			ll cost=pc.top()+-c.top().first;
			if(m>=cost)
			{
				pc.pop();
				pc.push(-pp[c.top().second]-cc[c.top().second]);
				h[c.top().second]=1;
				m-=cost;
			}
			else
				return !printf("%d\n",i);
		}
		else
		{
			if(m>=-p.top().first)
			{
				m-=-p.top().first;
				h[p.top().second]=1;
			}
			else
				return !printf("%d\n",i);
		}
	}
	printf("%d\n",n);
	return 0;
}
