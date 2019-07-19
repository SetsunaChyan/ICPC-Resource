#include <bits/stdc++.h>
using namespace std;
const int maxn=100+10;
int k;
char in[maxn],rst[28];
int main()
{
	scanf("%d %s",&k,in);
	int len=strlen(in),cnt=0;;
	for(char c=char('a'+k-1);c>='a';c--)
	{
		bool flag=true;
		for(int i=0;i<len;i++)
		{
			if(in[i]==c) 
			{
				flag=false;
				break;
			}
		}
		if(flag) rst[cnt++]=c;
	}
	
    int l,r,t=0;
    if(len&1) l=r=len/2;
    else l=len/2-1,r=len/2;
    while(l>=0)
    {
    	if(in[l]!='?' && in[r]!='?' && in[l]!=in[r])
    	{
    		cout<<"IMPOSSIBLE";
    		return 0;
		}
		else if(in[l]=='?' && in[r]=='?')
		{
			if(t<cnt) in[l]=in[r]=rst[t++];
			else in[l]=in[r]='a';//放满了以后放'a' 
		}
		else if(in[l]=='?') in[l]=in[r];
		else in[r]=in[l];
		l--,r++; 
	}
	if(t<cnt) printf("IMPOSSIBLE");
    else printf("%s",in);
	return 0;
}
