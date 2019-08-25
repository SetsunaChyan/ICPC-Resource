#include <bits/stdc++.h>
using namespace std;
long long int s[2000],ans=0,l,r;
bool flag=0;

void db()
{
	int n;
	for(int i=1;i<=1024;i++)
	{
		int a=i/2+1;
		if(i&1) n=5;
		else n=8;
		s[i]=s[i-a]*10+n;
	}
}

int main()
{
	cin>>l>>r;
	memset(s,0,sizeof(s));
	db();
	for(int i=1;i<=1024;i++)
	{
		if(s[i]>=l)
		{
			for(;l<=s[i];l++) 
			{
			   ans+=s[i];
			   if(l==r) 
			{
				flag=1;
				break;
			}
			}		
		}
		if(flag) break;
	}
	cout<<ans;
	return 0;
} 
