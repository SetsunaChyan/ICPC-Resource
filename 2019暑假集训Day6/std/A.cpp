#include <bits/stdc++.h>
using namespace std;
#define mod 1000
struct Node
{
	int e[2][2];
	Node()
	{
		memset(e,0,sizeof(e));
	}
};
int n;
//æÿ’Ûœ‡≥À 
Node mul(Node &a,Node &b)
{
	Node c;
	for(int i=0;i<2;i++)
     for(int j=0;j<2;j++)
      for(int k=0;k<2;k++)
       c.e[i][j]+=a.e[i][k]*b.e[k][j]%mod;
    
    return c;
}

//æÿ’ÛøÏÀŸ√› 
Node quick_pow(Node a,int b)
{
	Node c;
	c.e[0][0]=c.e[1][1]=1;
	while(b)
	{
		if(b&1) c=mul(c,a);
		a=mul(a,a);
		b>>=1;
	}
	return c;
}
int main()
{
    cin>>n;
    Node in;
    in.e[0][0]=3,in.e[0][1]=5;
    in.e[1][0]=1,in.e[1][1]=3;
    in=quick_pow(in,n);
    printf("%03d",(in.e[0][0]*2-1)%mod);
    return 0;
} 
