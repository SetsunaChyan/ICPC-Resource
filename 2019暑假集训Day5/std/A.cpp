#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=20000+10;
priority_queue<int,vector<int>,greater<int> > que;
ll n;
int main()
{
    cin>>n;
    ll tmp;
    for(int i=0;i<n;i++) 
	{
		cin>>tmp;
		que.push(tmp);
	}
	ll ans=0,low,up;
	while(que.size()>1)
	{
		low=que.top();
		que.pop();
		up=que.top();
		que.pop();
		ans+=low+up;
		que.push(low+up);
	}
	cout<<ans;
	return 0;
} 
