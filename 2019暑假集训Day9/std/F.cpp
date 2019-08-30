#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sd(a) scanf("%d",&a)
#define sld(a) scanf("%lld",&a)
#define pr(a) printf("%d",a)
#define per(a,b,c) for(int a=b;a<c;++a)
#define perr(a,b,c) for(int a=b;a<=c;++a)
const int inf=0x3f3f3f3f;
const int mod=2;

int _,n;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>_;
    while(_--)
    {
        cin>>s;
        int i=0;
        int l=s.size();
        for(i=0;i<l;++i)
            if(s[i]!='y')break;
        if(i<l&&s[i]!='z')s[i]+=1;
        cout<<s<<endl;
    }
    return 0;
}