#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 109;
int main(){
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    ll cnt = n;
    while(--m){
        cnt = (cnt * (n - 1)) % mod;
    }
    cout << cnt << endl;
    return 0;
}