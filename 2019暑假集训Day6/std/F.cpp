#include <bits/stdc++.h>
using namespace std;
int lx,ly,sx,sy,tx,ty;
int main()
{
	for(int i=0;i<10;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<10;j++) 
			if(s[j]=='L')
				lx=i,ly=j;
			else if(s[j]=='S')
				sx=i,sy=j;
			else if(s[j]=='T')
				tx=i,ty=j;
	}
	int dst=abs(sx-tx)+abs(sy-ty);
	int dls=abs(sx-lx)+abs(sy-ly);
	int dlt=abs(tx-lx)+abs(ty-ly);  
	if((sx==tx||sy==ty)&&dst==dls+dlt)
		printf("%d\n",dst+2);
	else
		printf("%d\n",dst);
  return 0;
}
