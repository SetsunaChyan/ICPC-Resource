#include <bits/stdc++.h>
using namespace std;
const int maxn=3010;
set<pair<int,int>> in;
int x[maxn],y[maxn],n,ans=0;
int main()
{
	cin>>n;
    for(int i=0;i<n;i++)
    {
    	cin>>x[i]>>y[i];
    	in.insert(make_pair(x[i],y[i]));
	}
	for(int i=0;i<n-1;i++)
	 for(int j=i+1;j<n;j++)
	 {
	 	if((x[i]+x[j])%2==0 && (y[i]+y[j])%2==0)
	 	{
	 		ans+=(in.find(make_pair((x[i]+x[j])/2,(y[i]+y[j])/2))!=in.end());
		}
	 }
	cout<<ans;
	return 0;
} 
