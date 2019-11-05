#include <bits/stdc++.h>
using namespace std;
int n,h,m,st=1e9,ed=-1;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d:%d",&h,&m);
		m+=h*60;
		if(m<6*60+30||m>19*60)
			continue;
		st=min(st,m);
		ed=max(ed,m);
	}
	if(ed==-1)
		printf("-1");
	else if(st<=10*60)
	{
		if(ed<=16*60)
			printf("A");
		else
			printf("B");
	}
	else if(ed<=16*60)
		printf("C");
	else
		printf("D");
	return 0;
}


