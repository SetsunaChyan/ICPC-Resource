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
		 if(s.rfind(s.substr(j,i))!=j)//rfind����find�������ǲ������һ�γ��ֵ�λ�ã�
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
