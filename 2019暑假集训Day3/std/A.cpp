#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int x,y,ans=0;
int main()
{
	char c;
	while((c=getchar())!='@')
	{
		switch(c)
		{
			case'+':x=s.top();s.pop();y=s.top();s.pop();s.push(x+y);break;
			case'-':x=s.top();s.pop();y=s.top();s.pop();s.push(y-x);break;
			case'*':x=s.top();s.pop();y=s.top();s.pop();s.push(x*y);break;
			case'/':x=s.top();s.pop();y=s.top();s.pop();s.push(y/x);break;
			case'.':s.push(ans);ans=0;break;
			default:ans=ans*10+c-'0';
		}
	}
	cout<<s.top();
	return 0;
}
