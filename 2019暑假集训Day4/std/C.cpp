#include <bits/stdc++.h>
using namespace std;
const int maxn=1000+10;
int in[maxn],n,l=0,r=0,cnt=0;
bool flag=false;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>in[i];
		if(in[i]!=i && l==0) l=i;
	}
	r=in[l];
	reverse(in+l,in+r+1);
	for(int i=1;i<=n;i++)
	{
		if(in[i-1]>in[i]) 
		{
			cout<<"No";
			return 0; 
		}
	}
    cout<<l<<' '<<r;
} 
