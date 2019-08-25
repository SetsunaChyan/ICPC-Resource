#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=100000+10;
ll b[maxn],n,m,t; 
 
struct bird
{
	ll e;
	ll m;
	bool operator<(const bird& a)const
	{
		return m>a.m;//射击目标物所需费用从小到大排列（优先队列的特殊性） 
	}
}in[maxn];

//目标物按照黑暗魔法值从大到小排列 
bool cmb(ll a,ll b)
{
	return a>b;
}

//能量球按照光明魔法值从大到小排列
bool cmi(bird a,bird b)
{
	return a.e>b.e;
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>m>>t)
	{
	if(!n && !m && !t) break;
	bool flag=0;
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<m;i++) cin>>in[i].e;
	for(int i=0;i<m;i++) cin>>in[i].m;
	sort(b,b+n,cmb);
	sort(in,in+m,cmi);
	ll ans=0;
	priority_queue<bird> que;
	for(int i=0,j=0;i<n;i++)
	{
		while(j<m && in[j].e>=b[i]) que.push(in[j++]);
		if(que.empty())//没有能量球能消灭第i只bird就退出 
		{
			flag=1;
			break;
		}
		ans+=que.top().m;//累加消灭第i只bird所需能量
		que.pop();//加完出队列 
	}
	if(flag || ans>t) cout<<"No"<<'\n';
	else cout<<"Yes"<<'\n';
	}

	return 0;
}
