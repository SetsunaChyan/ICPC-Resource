#include <cstdio>
#include <cctype>
#include <cstring>
#define  INF  (0x3f3f3f3f)
#define  Max(a,b)  ((a) > (b) ? (a) : (b))
#define  Min(a,b)  ((a) < (b) ? (a) : (b))
#define  N  (1000010)
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
    int f = 0, ch = 0; x = 0;
    for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
    for(; isdigit(ch); ch = getchar()) x = (x<<3) + (x<<1) + ch - '0';
    if(f) x = -x;
}
int n,d,max_x,max_y,tmp,ans;
int a[N][5],x[N][5],y[N][5];
bool zf[10];
void Get_Max(int p){
    if(p > d){
        max_x = -INF,max_y = -INF;
        for(int i = 1; i <= n; ++i){
            tmp = 0;
            for(int j = 1; j <= d; ++j) tmp += a[i][j] * (zf[j]?1:-1);
            max_x = Max(max_x, tmp);
            tmp = 0;
            for(int j = 1; j <= d; ++j) tmp += a[i][j] * (zf[j]?-1:1);
            max_y = Max(max_y, tmp);
        }
        ans = Max(ans, max_x + max_y);
        return;
    }
    zf[p] = 0, Get_Max(p+1);
    zf[p] = 1, Get_Max(p+1);
}
int main(){
    read(n),read(d);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= d; ++j)
            read(a[i][j]);
    memset(zf,0,sizeof(zf));
    Get_Max(1);
    printf("%d",ans);
    return 0;
}