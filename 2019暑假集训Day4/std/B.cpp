#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define mod 1000000007
const int maxn=1000+10;
ull in[maxn][maxn],s[maxn],n,m;
//C(n,0)=1,C(n,n)=1,C(0,0)=1,C(0,i|i>=1)=0
void db()
{
	for(int i=0;i<maxn;i++)
	{
		in[0][i]=0;
		in[i][0]=1;
		in[i][i]=1;
	}
	for(int i=1;i<maxn;i++)
	 for(int j=1;j<maxn;j++)
	  in[i][j]=(in[i-1][j]+in[i-1][j-1])%mod;
}
int main()
{
	cin>>n>>m;
	db();
	for(int i=0;i<n;i++) cin>>s[i];
	sort(s,s+n);
	ull sum=0;
	for(int i=0;i<n;i++)
	{
		if(n-i-1<m-1) break;
		sum+=s[i]*in[n-i-1][m-1];
		sum%=mod;
	}
	cout<<sum;
	return 0;
}
