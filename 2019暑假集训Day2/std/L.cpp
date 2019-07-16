#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll work(char* s,int k)
{
	ll res = 0;
	int n = strlen(s);
	for(int i = 0;i < n;i++)
		res = res * k + s[i]-'0';
	return res;
}
char s[20];
void solve()
{
	scanf("%s",s);
	ll ans = 0;
	for(int i = 2;i <= 10;i++)
		ans += work(s,i);
	printf("%lld\n",ans);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
