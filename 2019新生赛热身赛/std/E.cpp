#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
string s;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(s.find('+')!=s.npos) ans++;
		else ans--;
	}
	cout<<ans;
	return 0;
} 
