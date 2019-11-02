#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w,h,ans=0;
ll min(ll a,ll b)
{
	return a<b?a:b;
}
int main()
{
	cin>>w>>h;
	for(int i=1;i<=w;i++)
	 for(int j=1;j<=h;j++)
	 {
	 	ans+=min(i,w-i)*min(j,h-j);
	 }
	cout<<ans;
	return 0;
}
