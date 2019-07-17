#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k;
ll ans;
ll a;
int main()
{
    cin>>k;
    ll num=2*k;
    ll maxx=sqrt(num)+1;
    for(ll i=maxx;i>=1;i--)
    {
        if((num-i*i+i)%(2*i)==0&&(num-i*i+i)>0)//枚举n
        {
            ans=i;
            break;
        }
    }
    a=(num-ans*ans+ans)/(2*ans);
    cout<<a;
    putchar(' ');
    cout<<(a+ans-1)<<endl;
    return 0;
}