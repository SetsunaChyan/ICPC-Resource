#include <bits/stdc++.h>
using namespace std;
#define inf -1000000
const int maxn=1010;
int in[maxn][maxn],d[maxn][maxn],n,m,r,c,t,ans;
int main()
{
	cin>>n>>m>>t;
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)
	 for(int j=1;j<=m;j++)
	 {
	 	cin>>in[i][j];
	 	d[i][j]=d[i-1][j]+d[i][j-1]+in[i][j]-d[i-1][j-1];
	 }
	ans=inf;
	for(r=1;r<=min(10,n);r++)
	{
	  int tmp=inf;
	  for(c=1;c<=min(10,m);c++)
	  {
	  	for(int i=1;i<=n-r+1;i++)
	      for(int j=1;j<=m-c+1;j++)
	      {
	      	tmp=max(tmp,d[i+r-1][j+c-1]-d[i-1][j+c-1]-d[i+r-1][j-1]+d[i-1][j-1]);
		  }
	   tmp-=r*c*t;
	   if(tmp>ans) ans=tmp;
	  }	   
	}	     	
	if(ans>0) cout<<ans; 
	else cout<<0;
	return 0;
} 
