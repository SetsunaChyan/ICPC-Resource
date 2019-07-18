#include <bits/stdc++.h>
using namespace std;
const int maxn=20;
int in[maxn],n,k=3,sum=0;

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

void fun()
{
	for(int i=1;i<1<<k;i++)
	{
		int ans=1,cnt=0;
		for(int j=0;j<k;j++)
		{
			if(i & (1<<j)) ans=ans*in[j]/gcd(ans,in[j]),cnt++;
		}
		if(cnt & 1) 
		{
			if(cnt==1) sum+=n/ans;
			else sum+=n/ans*4;
		}
		else sum-=n/ans*2;
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<k;i++) cin>>in[i];
	fun();
	cout<<sum;
	return 0;
}
