#include <bits/stdc++.h>
using namespace std;
int n,ans=0;

int main()
{
	while(cin>>n)
	{
		if(n==0) break;
		ans=0;
		while(n!=1)
		{
			if(n%3==0) n/=3;
			else n=n/3+1;
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
