#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll j,jx,jxc,jxcn,jxcnb;
int main()
{
    string s;
    int l;
    cin>>l>>s;
    for(int i=0;i<l;++i){
        if(s[i]=='j')j++;
        if(s[i]=='x')jx+=j;
        if(s[i]=='c')jxc+=jx;
        if(s[i]=='n')jxcn+=jxc;
        if(s[i]=='b')jxcnb+=jxcn;
    }
    cout<<jxcnb<<endl;
}