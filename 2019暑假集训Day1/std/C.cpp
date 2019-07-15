#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	bool flag=false;
	cin>>s;
	int len=s.size();
	for(int i=len;i>=0;i--)
	{
		for(int j=0;j<len;j++)
	 {
		 if(s.rfind(s.substr(j,i))!=j)//rfind（和find的区别是查找最后一次出现的位置）
	 	{	
			cout<<i;
			flag=true;
			break; 
		 }
	 }
	 if(flag) break;
	}	 	 
	if(!flag) cout<<0;
	return 0;
}
