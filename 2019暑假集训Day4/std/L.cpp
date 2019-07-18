#include <iostream>
using namespace std;

int main()
{
    int n,i,ans;
    cin>>n;
    i=1; ans=0;
    do 
    {
        i=(i*2)%(2*n+1);
        ans++;
    }
    while (i!=1);
    cout<<ans<<endl;
}