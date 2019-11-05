#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MN=3e3+5;
int n,g[MN],s[MN],t;
bitset<MN> npr;

int main()
{
	for(int i=2;i<MN;++i)
		if(!npr[i])
		{
			g[i]=1;
			for(int j=i;j<MN;j+=i) npr[j]=1;
			for(int j=i;j<MN;j*=i) g[j]=i;
		}
        else
            if(!g[i]) g[i]=1;
	for(int i=3;i<MN;++i) s[i]=s[i-1]+g[i];
	scanf("%d",&t);
	while(t--) scanf("%d",&n),printf("%d\n",s[n]);
	return 0;
}
