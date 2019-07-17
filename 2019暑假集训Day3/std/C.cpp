#include <bits/stdc++.h>
using namespace std;
const int maxn=1300000;
vector<int> primes;
bool flag[maxn];
int n;
void db()
{
	memset(flag,0,sizeof(flag));
	int k=sqrt(maxn);
	for(int i=2;i<=k;i++)
	{
		if(!flag[i])
		{
			for(int j=i*i;j<maxn;j+=i) flag[j]=1;
		}
	}
	for(int i=2;i<maxn;i++)
	{
		if(!flag[i]) primes.push_back(i);
	}
}
int main()
{
	db();
	cin>>n;
	if(!flag[n]) cout<<0;
	else
	{
		vector<int>::iterator it;
		it=lower_bound(primes.begin(),primes.end(),n);//返回第一个大于等于n的素数地址 
		int l=*(it-1),r=*it;
		cout<<r-l;
	}
	return 0;
 } 
