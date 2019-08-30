#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=500000+2;
ll in[maxn],tmp[maxn],n,ans=0;

void gb(int head,int tail)
{
	if(head==tail) return;
	int mid=head+((tail-head)>>1);
	gb(head,mid);//�鲢ǰ�벿��
	gb(mid+1,tail);//�鲢��벿�� 
	int i=head,j=mid+1,k=head;
	while(i<=mid && j<=tail)
	{
		if(in[i]>in[j])
		{
			tmp[k++]=in[j++];
			ans+=mid-i+1;
		}
		else
		{
			tmp[k++]=in[i++];
		}
	}
	while(i<=mid) tmp[k++]=in[i++];
	while(j<=tail) tmp[k++]=in[j++];
	for(int a=head;a<=tail;a++) in[a]=tmp[a];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>in[i];
	gb(1,n);
//	for(int i=1;i<=n;i++) cout<<in[i]<<' ';
	cout<<ans;
	return 0;
} 
